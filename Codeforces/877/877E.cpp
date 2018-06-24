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
int subTreeSize[200010],idx[200010],arr[200010];
vi adj[200010],path;
bool vis[200010];

void dfs(int i){
    vis[i]=true;
    path.pb(i);

    for(int x : adj[i])
        if(!vis[x]){
            dfs(x);
            subTreeSize[i]+=subTreeSize[x];
        }
    ++subTreeSize[i];
}

int lazyTree[1 <<20],segTree[1 << 20];
void buildTree(int low,int high,int pos){
    int mid=(low+high) >> 1;
    if(low==high)
        segTree[pos]=arr[mid];
    else{
        buildTree(low,mid,2*pos+1);
        buildTree(mid+1,high,2*pos+2);
        segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
    }
}

void updateTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high) >> 1;
    if(lazyTree[pos] & 1){
        segTree[pos]=(high-low+1-segTree[pos]);
        if(low!=high){
            lazyTree[2*pos+1]+=lazyTree[pos];
            lazyTree[2*pos+2]+=lazyTree[pos];
        }
    }
    lazyTree[pos]=0;

    if(qLow>high || qHigh<low)
        return ;
    else if(qLow<=low && qHigh>=high){
        segTree[pos]=(high-low+1-segTree[pos]);
        if(low!=high){
            ++lazyTree[2*pos+1];
            ++lazyTree[2*pos+2];
        }
    }
    else{
        updateTree(low,mid,2*pos+1,qLow,qHigh);
        updateTree(mid+1,high,2*pos+2,qLow,qHigh);
        segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
    }

}

int queryTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high) >> 1;
    if(lazyTree[pos] & 1){
        segTree[pos]=(high-low+1-segTree[pos]);
        if(low!=high){
            lazyTree[2*pos+1]+=lazyTree[pos];
            lazyTree[2*pos+2]+=lazyTree[pos];
        }
    }
    lazyTree[pos]=0;

    if(qLow>high || qHigh<low)
        return 0;
    else if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else
        return (queryTree(low,mid,2*pos+1,qLow,qHigh)+queryTree(mid+1,high,2*pos+2,qLow,qHigh));
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;
    FOR(i,2,n+1){
        int p;
        cin>>p;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    int temp[n+1];
    FOR(i,1,n+1)
        cin>>temp[i];

    dfs(1);

    REP(i,n){
        idx[path[i]]=i;
        arr[i]=temp[path[i]];
    }
    buildTree(0,n-1,0);

    int q;
    cin>>q;
    REP(i,q){
        string str;
        int v;
        cin>>str>>v;

        if(str=="get")
            cout<<queryTree(0,n-1,0,idx[v],idx[v]+subTreeSize[v]-1)<<endl;
        else
            updateTree(0,n-1,0,idx[v],idx[v]+subTreeSize[v]-1);
    }
    return 0;
}
