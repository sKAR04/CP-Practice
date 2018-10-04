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
int mtrx[110][110];
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    int a[n],b[m];

    int row=0,col=0;
    REP(i,n){
        cin>>a[i];
        row^=a[i];
    }
    REP(i,m){
        cin>>b[i];
        col^=b[i];
    }

    if(row!=col)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        mtrx[1][1]=b[0]^row^a[0];
        FOR(i,2,n+1)
            mtrx[i][1]=a[i-1];
        FOR(j,2,m+1)
            mtrx[1][j]=b[j-1];

        FOR(i,1,n+1){
            FOR(j,1,m+1)
                cout<<mtrx[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}
