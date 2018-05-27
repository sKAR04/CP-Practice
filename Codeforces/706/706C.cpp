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
string str[100010],rev[100010];
ll cost[100010];
ll dp[100010][2];
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;
    FOR(i,1,n+1){
        cin>>cost[i];
        dp[i][0]=dp[i][1]=LLONG_MAX;
    }

    FOR(i,1,n+1){
        string temp;
        cin>>temp;

        str[i]=temp;
        reverse(all(temp));
        rev[i]=temp;
    }

    dp[1][0]=0;
    dp[1][1]=cost[1];
    FOR(i,2,n+1){
        if(str[i]>=str[i-1] && dp[i-1][0]!=LLONG_MAX)
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(str[i]>=rev[i-1] && dp[i-1][1]!=LLONG_MAX)
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(rev[i]>=str[i-1] && dp[i-1][0]!=LLONG_MAX)
            dp[i][1]=min(dp[i][1],dp[i-1][0]+cost[i]);
        if(rev[i]>=rev[i-1] && dp[i-1][1]!=LLONG_MAX)
            dp[i][1]=min(dp[i][1],dp[i-1][1]+cost[i]);
    }

    ll ans=min(dp[n][0],dp[n][1]);
    if(ans==LLONG_MAX)
        ans=-1;
    cout<<ans<<endl;

    return 0;
}
