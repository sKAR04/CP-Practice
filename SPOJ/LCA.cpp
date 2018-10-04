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
int n,qLow,qHigh,root;
bool vis[1010],notRoot[1010];
int h[1010],id[1010],tree[10010];
vi path,adj[1010];

void build(int low,int high,int pos){
    int mid=(low+high)>>1;

    if(low==high)
        tree[pos]=path[mid];
    else{
        build(low,mid,2*pos+1);
        build(mid+1,high,2*pos+2);
        if(h[tree[2*pos+1]]>h[tree[2*pos+2]])
            tree[pos]=tree[2*pos+2];
        else
            tree[pos]=tree[2*pos+1];
    }
}

int query(int low,int high,int pos){
    int mid=(low+high)>>1;

    if(qLow>high || qHigh<low)
        return n+1;
    else if(qLow<=low && qHigh>=high)
        return tree[pos];
    else{
        int l=query(low,mid,2*pos+1),r=query(mid+1,high,2*pos+2);
        if(h[l]>h[r])
            return r;
        else
            return l;
    }
}

void dfs(int cur){
    vis[cur]=true;
    id[cur]=path.size();
    path.pb(cur);

    for(int ch : adj[cur]){
        if(!vis[ch]){
            h[ch]=h[cur]+1;
            dfs(ch);
            path.pb(cur);
        }
    }
}

inline void solve(){
    h[root]=0;
    dfs(1);
    build(0,2*(n-1),0);
    h[n+1]=INF;

    int q;
    cin>>q;
    while(q--){
        int v1,v2;
        cin>>v1>>v2;

        v1=id[v1],v2=id[v2];
        qLow=min(v1,v2);
        qHigh=max(v1,v2);
        cout<<query(0,2*(n-1),0)<<endl;
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    FOR(i,1,t+1){
        cout<<"Case "<<i<<":"<<endl;
        cin>>n;

        FOR(i,1,n+1){
            adj[i].clear();
            vis[i]=false;
        }
        path.clear();

        FOR(i,1,n+1){
            int sz;
            cin>>sz;
            REP(j,sz){
                int v;
                cin>>v;
                adj[i].pb(v);
                adj[v].pb(i);
                notRoot[v]=true;
            }
        }

        FOR(i,1,n+1)
            if(!notRoot[i]){
                root=i;
                break;
            }
        solve();
    }

    return 0;
}
