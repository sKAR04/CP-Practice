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
typedef long long ll;
typedef long double ld;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001

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
ld prob[20][20];
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;

    REP(i,n)
        REP(j,n)
            cin>>prob[i][j];


    ld dp[1LL << n]={};
    dp[(1LL << n)-1LL]=1;

    DFOR(mask,(1LL << n)-1LL,0LL){
        ll aliveCnt=0;
        REP(j,n)
            if(mask & (1LL << j))
                ++aliveCnt;

        if(aliveCnt>1LL){
            ld fightProb=(ld)2/((ld)aliveCnt*(ld)(aliveCnt-1LL));
            REP(j,n)
                REP(k,n)
                    if((mask & (1LL << j)) && (mask & (1LL << k)))
                        dp[mask & ~(1LL << k)]+=(dp[mask]*prob[j][k]*fightProb);
        }
    }

    REP(i,n)
        cout<<setprecision(20)<<dp[(1LL << i)]<<" ";
    cout<<endl;

    return 0;
}
