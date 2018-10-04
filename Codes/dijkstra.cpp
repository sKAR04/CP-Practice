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
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
int n,m;
vii adj[100010];
bool relaxed[100010];
int dist[100010];

inline void dijkstra(){
    FOR(i,1,n+1)
        dist[i]=1e9;

    PQ<pi,vii,greater<pi>> q;
    dist[1]=0;
    q.push(mp(0,1));
    while(!q.E){
        int cur=q.top().S;
        q.pop();

        if(!relaxed[cur]){
            relaxed[cur]=true;
            for(pi p : adj[cur])
                if(!relaxed[p.S] && dist[p.S]>dist[cur]+p.F){
                    dist[p.S]=dist[cur]+p.F;
                    q.push(mp(dist[p.S],p.S));
                }
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;
    REP(i,m){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].pb(mp(w,v2));
    }

    dijkstra();

    FOR(i,2,n+1)
        cout<<dist[i]<<" ";
    cout<<endl;

    return 0;
}
