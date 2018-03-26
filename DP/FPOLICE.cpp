/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

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
#define TIE cin.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Input methods
template <typename T>
void getFoo(T &x){
    x=0;
    register char c=gc();
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
}

template <typename T1,typename T2>
void getFoo(T1 &x,T2 &y){
    getFoo(x);
    getFoo(y);
}

template <typename T1,typename T2,typename T3>
void getFoo(T1 &x,T2 &y,T3 &z){
    getFoo(x);
    getFoo(y);
    getFoo(z);
}
//Declare all variables and methods needed between this comment and the next one(OCD lol)
ll timeTaken[110][110];
ll riskInvolved[110][110];
ll dp[110][260];

inline void solve(){
    int n,t;
    cin>>n>>t;

    FOR(i,1,n+1)
        FOR(j,1,n+1)
            cin>>timeTaken[i][j];

    FOR(i,1,n+1)
        FOR(j,1,n+1)
            cin>>riskInvolved[i][j];

    REP(i,n+1)
        REP(j,t+1)
            dp[i][j]=LLONG_MAX;

    dp[1][0]=0LL;
    REP(j,t)
        FOR(i,1,n+1)
            if(dp[i][j]!=LLONG_MAX)
                FOR(k,1,n+1)
                    if(j+timeTaken[i][k]<=t)
                        dp[k][j+timeTaken[i][k]]=min(dp[k][j+timeTaken[i][k]],dp[i][j]+riskInvolved[i][k]);

    int ans=-1;
    ll minRisk=LLONG_MAX;
    REP(i,t+1)
        if(minRisk>dp[n][i]){
            ans=i;
            minRisk=dp[n][i];
        }

    if(ans==-1)
        cout<<-1<<endl;
    else
        cout<<minRisk<<" "<<ans<<endl;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}
