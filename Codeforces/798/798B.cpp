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
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
ll dp[60][60];
string str[60],mod[60];
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;

    REP(i,n)
        cin>>str[i];

    REP(i,60)
        REP(j,60)
            dp[i][j]=INF;

    ll len=str[0].length();
    REP(i,len){
        mod[i]=str[0];
        str[0]=str[0].substr(1)+str[0][0];
        dp[0][i]=i;
    }

    FOR(i,1,n)
        REP(j,len){
            REP(k,len)
                if(str[i]==mod[k])
                    dp[i][k]=min(dp[i][k],dp[i-1][k]+j);
            str[i]=str[i].substr(1)+str[i][0];
        }

    ll ans=INF;
    REP(j,len)
        ans=min(ans,dp[n-1][j]);
    if(ans==INF)
        cout<<-1;
    else
        cout<<ans;
    cout<<endl;

    return 0;
}
