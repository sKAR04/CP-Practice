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
#define vii vector<pair<int,int> >
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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
ll dp[200010];
//Main function
int main(){
    IOS;
    TIE;

    int q;
    cin>>q;

    double avg=0;
    int n=1,last=0;

    REP(i,q){
        int t;
        cin>>t;

        if(t==1){
            int a,x;
            cin>>a>>x;

            dp[a]-=x;
            if(a==n)
                last+=x;
            avg=(avg*n+(double)x*a)/(double)n;
        }
        else if(t==2){
            cin>>last;
            avg=(avg*n+(double)last)/((double)n+1.0);
            dp[n]+=last;
            ++n;
            dp[n]-=last;
        }
        else{
            avg=(avg*n-(double)last)/((double)n-1.0);
            dp[n]=0;
            --n;
            last=last-dp[n];
            dp[n]=-last;
        }
        cout<<setprecision(20)<<avg<<endl;
    }

    return 0;
}
