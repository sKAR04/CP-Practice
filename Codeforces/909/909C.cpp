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
#define MOD  1000000007
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
int dp[5010][5010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    char type[n];
    REP(i,n)
        cin>>type[i];

    dp[0][1]=1;
    int maxIdt=1;
    FOR(i,1,n)
        if(type[i-1]=='f'){
            FOR(j,1,maxIdt+1){
                dp[i][j+1]=(dp[i-1][j]-dp[i-1][j-1]+dp[i][j]);
                if(dp[i][j+1]<0)
                    dp[i][j+1]+=MOD;
                dp[i][j+1]%=MOD;
            }
            ++maxIdt;
        }
        else
            FOR(j,1,maxIdt+1){
                dp[i][j]=(dp[i-1][maxIdt]-dp[i-1][j-1]+dp[i][j-1]);
                if(dp[i][j]<0)
                    dp[i][j]+=MOD;
                dp[i][j]%=MOD;
            }

    cout<<dp[n-1][maxIdt]<<endl;

    return 0;
}
