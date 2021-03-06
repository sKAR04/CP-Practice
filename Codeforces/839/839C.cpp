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
vi adj[100010];
double dp[100010];
int level[100010];
bool isLeaf[100010],vis[100010];

void dfs(int i,int l,double prob){
    vis[i]=true;
    level[i]=l;
    dp[i]=prob;

    int cnt=0;
    for(int x : adj[i])
        if(!vis[x])
            ++cnt;

    if(!cnt)
        isLeaf[i]=true;
    else
        for(int x : adj[i])
            if(!vis[x])
                dfs(x,level[i]+1,dp[i]/(double)cnt);
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    REP(i,n-1){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    dfs(1,0,1.0);

    double len=0;
    FOR(i,1,n+1)
        if(isLeaf[i])
            len+=(dp[i]*level[i]);

    cout<<setprecision(20)<<len<<endl;

    return 0;
}
