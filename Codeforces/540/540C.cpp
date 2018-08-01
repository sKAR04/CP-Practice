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
int n,m;
bool vis[510][510];
char grid[510][510];
pi src,dest;

vii fml;

void dfs(pi cur){
    vis[cur.F][cur.S]=true;
    pi adj[4]={mp(cur.F+1,cur.S),mp(cur.F-1,cur.S),mp(cur.F,cur.S+1),mp(cur.F,cur.S-1)};
    for(pi p : adj)
        if(p.F>=0 && p.F<n && p.S>=0 && p.S<m && grid[p.F][p.S]=='.' && !vis[p.F][p.S])
            dfs(p);
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;
    REP(i,n)
        REP(j,m)
            cin>>grid[i][j];
    cin>>src.F>>src.S>>dest.F>>dest.S;
    --src.F,--src.S,--dest.F,--dest.S;

    bool destIsBroken=(grid[dest.F][dest.S]=='X');
    grid[dest.F][dest.S]='.';
    grid[src.F][src.S]='.';
    dfs(src);

    int cnt=0;
    pi adj[4]={mp(dest.F+1,dest.S),mp(dest.F-1,dest.S),mp(dest.F,dest.S+1),mp(dest.F,dest.S-1)};
    for(pi p : adj)
        if(p.F>=0 && p.F<n && p.S>=0 && p.S<m && grid[p.F][p.S]=='.')
            ++cnt;

    if(!vis[dest.F][dest.S])
        cout<<"NO"<<endl;
    else if(destIsBroken){
        if(src!=dest)
            cout<<"YES"<<endl;
        else if(cnt)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else if(cnt>1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
