/*
######################################################
#    I don't know what I'm doing with my life O.O    #
######################################################
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
const int MAXN=2e5+10;
vi adj[MAXN][2];
ll cnt[MAXN][2];
bool vis[MAXN][2];
vi v;
void dfs(int cur,int color){
    vis[cur][color]=true;
    v.pb(cur);
    for(int x : adj[cur][color])
        if(!vis[x][color])
            dfs(x,color);
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    int x,y,w;
    REP(i,n-1){
        cin>>x>>y>>w;
        adj[x][w].pb(y);
        adj[y][w].pb(x);
    }

    REP(j,2)
        FOR(i,1,n+1)
            if(!vis[i][j]){
                dfs(i,j);
                for(int x : v)
                    cnt[x][j]=v.size()-1;
                v.clear();
            }

    ll ans=0;
    FOR(i,1,n+1)
        ans+=(cnt[i][0]+cnt[i][1]);
    // db(ans);

    memset(vis,false,sizeof(vis));

    ll sum;
    FOR(i,1,n+1)
        if(!vis[i][0]){
            dfs(i,0);
            sum=0LL;

            // db(i);
            // db(ans);
            for(int x : v)
                sum+=cnt[x][1];

            for(int x : v)
                ans+=(sum-cnt[x][1]);
            v.clear();
            // db(ans);
        }
    cout<<ans<<endl;

    return 0;
}
