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
#define INF 0X3f3f3f3f

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
int color[100010];
set<int> colors[100010];
vi adj[100010];
bool vis[100010];

void dfs(int i){
    vis[i]=true;

    for(int x : adj[i]){
        if(color[i]!=color[x])
            colors[color[i]].insert(color[x]);
        if(!vis[x])
            dfs(x);
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    FOR(i,1,n+1)
        cin>>color[i];

    REP(i,m){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    FOR(i,1,n+1)
        if(!vis[i])
            dfs(i);

    int maxDiversity=INT_MIN;
    int maxColor=color[1];
    FOR(i,1,n+1)
        if(maxDiversity<int(colors[color[i]].size())){
            maxDiversity=colors[color[i]].size();
            maxColor=color[i];
        }
        else if(maxDiversity==int(colors[color[i]].size()))
            maxColor=min(maxColor,color[i]);
    cout<<maxColor<<endl;

    return 0;
}
