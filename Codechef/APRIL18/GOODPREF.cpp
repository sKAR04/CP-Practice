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
ll n;
ll getCount(ll a,ll b,ll c,ll d){
    ll ans;

    if(b>d)
        ans=n-(ll)floor((double)(c-a)/(double)(b-d))-1;
    else if(b==d){
        if(a>c)
            ans=n;
        else
            ans=0;
    }
    else
        ans=(ll)ceil((double)(a-c)/(double)(d-b));


    ans=max(ans,0LL);
    ans=min(ans,n);

    return ans;
}

inline ll solve(){
    string str;

    cin>>str>>n;

    int len=str.length();

    ll dp[len+1][2];
    dp[0][0]=dp[0][1]=0LL;

    FOR(i,1,len+1){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];

        if(str[i-1]=='a')
            ++dp[i][0];
        else
            ++dp[i][1];
    }

    ll ans=0;
    FOR(i,1,len+1)
        ans+=getCount(dp[i][0],dp[len][0],dp[i][1],dp[len][1]);

    return ans;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        cout<<solve()<<endl;

    return 0;
}
