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
int n;
bool graph[1010][1010][5];
int inCnt[1010];
vi adj[1010];
int dp[1010];

inline vi topSort(){
    qi q;
    FOR(i,1,n+1)
        if(!inCnt[i])
            q.push(i);

    vi ans;
    while(!q.E){
        int cur=q.front();
        ans.pb(cur);
        for(int v : adj[cur]){
            --inCnt[v];
            if(!inCnt[v])
                q.push(v);
        }
        q.pop();
    }

    return ans;
}

int maxPath(vi sorted){
    fill(dp,dp+1010,INF);

    REP(i,n){
        if(dp[sorted[i]]==INF)
            dp[sorted[i]]=0;
        for(int v : adj[sorted[i]])
            dp[v]=(dp[v]>dp[sorted[i]]-1)?dp[sorted[i]]-1:dp[v];
    }

    int ans=INF;
    FOR(i,1,n+1)
        ans=(ans>dp[i])?dp[i]:ans;
    return -ans;
}
//Main function
int main(){
    IOS;
    TIE;

    int k;
    cin>>n>>k;

    REP(l,k){
        int arr[n];
        REP(i,n){
            cin>>arr[i];
            REP(j,i)
                graph[arr[j]][arr[i]][l]=1;
        }
    }

    FOR(i,1,n+1)
        FOR(j,1,n+1){
            bool flag=true;
            REP(l,k)
                flag&=graph[i][j][l];

            if(flag){
                adj[i].pb(j);
                ++inCnt[j];
            }
        }

    vi sorted=topSort();
    cout<<maxPath(sorted)+1<<endl;

    return 0;
}
