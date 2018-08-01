/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

//Optimizations
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//save time
#define endl '\n'
#define db(x) cout << "> " << #x << ": " << x << endl;
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f

//loops
#define REP(i,n) 	    for(ll i=0;i<(n);++i)
#define FOR(i,a,b)      for(ll i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(ll i=(a);i>=(b);--i)

//vectors
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pair<int,int>>
#define vlll vector<pair<ll,ll>>
#define pb 	push_back

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//fast I/O
#ifndef _WIN32
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define gc getchar
#define pc putchar
#define scan getFoo

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int n,m;
int p[40];

void genP(){
    REP(i,n){
        cout<<1<<endl;
        fflush(stdout);

        int response;
        cin>>response;

        if(!response)
            exit(0);
        else if(response==1)
            p[i]=1;
    }
}

void bSearch(int low,int high,int cnt){
    int mid=(low+high)>>1;
    cout<<mid<<endl;
    fflush(stdout);

    int response;
    cin>>response;

    if(!response)
        exit(0);
    else if(response==1){
        if(p[cnt])
            bSearch(mid+1,high,(cnt+1)%n);
        else
            bSearch(low,mid-1,(cnt+1)%n);
    }
    else{
        if(p[cnt])
            bSearch(low,mid-1,(cnt+1)%n);
        else
            bSearch(mid+1,high,(cnt+1)%n);
    }
}
//Main function
int main(){
    //IOS;
    //TIE;

    cin>>m>>n;
    genP();
    bSearch(1,m,0);

    return 0;
}
