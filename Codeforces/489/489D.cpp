//Strike me down and I shall become stronger, than you can possibly imagine
//Streak Count : 1
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
int n,m;
ll cnt[3010];
vi adj[3010];

ll ans;

void dfs(int x,int par,int depth){
    if(depth==2)
        ++cnt[x];
    else{
        for(int v : adj[x])
            if(v!=par)
                dfs(v,x,depth+1);
    }
}

void addCnt(){
    FOR(i,1,n+1){
        ans+=((cnt[i])*(cnt[i]-1)/2LL);
        cnt[i]=0;
    }
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    REP(i,m){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
    }

    FOR(i,1,n+1){
        dfs(i,0,0);
        addCnt();
    }

    cout<<ans<<endl;

    return 0;
}
