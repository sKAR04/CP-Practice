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

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
ll dp[1LL << 18][18];
ll dishes[20];
ll rules[20][20];
//Main function
int main(){
    IOS;
    TIE;

    ll n,m,k;
    cin>>n>>m>>k;

    REP(i,n)
        cin>>dishes[i];

    REP(i,k){
        ll a,b,c;
        cin>>a>>b>>c;
        rules[a-1][b-1]=c;
    }

    REP(i,n)
        dp[(1LL << i)][i]=dishes[i];

    ll ans=0;
    REP(mask,(1LL << n)){
        ll numOfOnes=0;
        REP(i,n)
            if(mask & (1LL << i))
                ++numOfOnes;

        if(numOfOnes==m)
            REP(i,n)
                ans=max(ans,dp[mask][i]);

        else if(numOfOnes<m)
            REP(i,n)
                if(mask & (1LL << i))
                    REP(j,n)
                        if(!(mask & (1LL << j)))
                            dp[mask | (1LL << j)][j]=max(dp[mask | (1LL << j)][j],dp[mask][i]+dishes[j]+rules[i][j]);
    }

    cout<<ans<<endl;

    return 0;
}
