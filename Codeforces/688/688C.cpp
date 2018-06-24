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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
bool vis[100010];
vi adj[100010];

bool foo[100010],bar[100010];
vi pari,arya;

bool notPossible;

void dfs(int i,bool flag){
    vis[i]=true;
    if(flag){
        pari.pb(i);
        foo[i]=true;
    }
    else{
        arya.pb(i);
        bar[i]=true;
    }

    for(int v : adj[i])
        if(!vis[v])
            dfs(v,!flag);
        else if(foo[i] && foo[v])
            notPossible=true;
        else if(bar[i] && bar[v])
            notPossible=true;
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    REP(i,m){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    FOR(i,1,n+1)
        if(!vis[i])
            dfs(i,false);

    if(notPossible)
        cout<<-1<<endl;
    else{
        cout<<arya.size()<<endl;
        for(int x : arya)
            cout<<x<<" ";
        cout<<endl;

        cout<<pari.size()<<endl;
        for(int x : pari)
            cout<<x<<endl;
    }
    return 0;
}
