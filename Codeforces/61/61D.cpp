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
ll maxPathLen;
vector<pair<int,ll> > adj[100010];
bool vis[100010];

void dfs(int i,ll cnt){
    bool flag=true;
    vis[i]=true;

    for(auto p : adj[i])
        if(!vis[p.F]){
            dfs(p.F,cnt+p.S);
            flag=false;
        }

    if(flag)
        maxPathLen=max(maxPathLen,cnt);
}


//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;

    ll totSum=0;

    REP(i,n-1){
        int v1,v2;
        ll w;
        cin>>v1>>v2>>w;
        adj[v1].pb(mp(v2,w));
        adj[v2].pb(mp(v1,w));
        totSum+=w;
    }

    dfs(1,0);

    cout<<2LL*totSum-maxPathLen<<endl;

    return 0;
}
