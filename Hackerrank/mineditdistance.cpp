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
void solve(){
    string str0,str1;
    cin>>str0>>str1;

    int n=str0.length(),m=str1.length();
    int dp[n+1][m+1];
    memset(dp,sizeof(dp),0);
    REP(i,n+1)
        dp[i][0]=i;

    REP(j,m+1)
        dp[0][j]=j;

    str0=" "+str0;
    str1=" "+str1;
    FOR(i,1,n+1)
        FOR(j,1,m+1)
            if(str0[i]==str1[j])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                ++dp[i][j];
            }

    cout<<dp[n][m]<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
