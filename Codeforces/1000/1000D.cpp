//Read the question properly you Kaneki piece of shit
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
#define MOD  998244353LL
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
ll dp[1010][1010];
ll good[1010];
//Main function
int main(){
    IOS;
    TIE;

    REP(i,1010)
        dp[i][0]=1LL;

    FOR(i,1,1010)
        FOR(j,1,1010)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;

    ll n;
    cin>>n;

    ll arr[n+1];
    FOR(i,1,n+1)
        cin>>arr[i];

    good[n+1]=1LL;
    DFOR(i,n,1)
        if(arr[i]>0 && arr[i]<1010)
            DFOR(j,n,i)
                good[i]=(good[i]+(dp[j-i][arr[i]]*good[j+1])%MOD)%MOD;

    ll ans=0LL;
    FOR(i,1,n+1)
        ans=(ans+good[i])%MOD;
    cout<<ans<<endl;

    return 0;
}
