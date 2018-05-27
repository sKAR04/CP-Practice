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
ll cost[100010];
vi adj[100010],revAdj[100010];
bool vis[100010],revVis[100010];
vector<vi > components;

void dfs(int i,vi &v){
    vis[i]=true;
    for(int x : adj[i])
        if(!vis[x])
            dfs(x,v);
    v.pb(i);
}

void revDfs(int i,vi &v){
    revVis[i]=true;
    v.pb(cost[i]);
    for(int x : revAdj[i])
        if(!revVis[x])
            revDfs(x,v);
}
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;

    FOR(i,1,n+1)
        cin>>cost[i];

    ll m;
    cin>>m;
    REP(i,m){
        ll v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        revAdj[v2].pb(v1);
    }

    vi v;
    FOR(i,1,n+1)
        if(!vis[i])
            dfs(i,v);



    int len=v.size();
    DFOR(i,len-1,0)
        if(!revVis[v[i]]){
            vi temp;
            revDfs(v[i],temp);
            components.pb(temp);
        }

    ll minCost=0LL;
    ll ways=1LL;
    for(vi v : components){
        sort(all(v));
        minCost+=v[0];

        ll cnt=0;
        for(int x : v)
            if(x==v[0])
                ++cnt;
        ways=(ways*cnt)%MOD;
    }
    cout<<minCost<<" "<<ways<<endl;

    return 0;
}
