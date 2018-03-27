
//Strike me down and I shall become stronger, than you can possibly imagine

#include <bits/stdc++.h>
using namespace std;

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
#define pf push_front

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//general
#define E empty()

//Variables and Functions required
int n,m,cnt;
vi adj[200010];
bool cat[200010];
bool vis[200010];
void dfs(int i,int streak){
    vis[i]=true;
    if(cat[i])
        ++streak;
    else
        streak=0;
    if(streak>m)
        return ;
    bool isLeaf=true;
    for(int x : adj[i])
        if(!vis[x]){
            dfs(x,streak);
            isLeaf=false;
        }
    if(isLeaf)
        ++cnt;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n+1)
        cin>>cat[i];
    REP(i,n-1){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    dfs(1,0);
    cout<<cnt<<endl;
    return 0;
}
