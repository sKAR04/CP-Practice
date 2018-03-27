
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
vi adj[100010];
int color[100010];

bool subTreeColor(int idx,int par,int treeCol){
    bool ans=true;
    for(int x : adj[idx])
        if(x!=par)
            ans&=subTreeColor(x,idx,treeCol);
    if(color[idx]!=treeCol)
        ans=false;
    return ans;
}

bool check(int idx){
    bool ans=true;
    for(int x : adj[idx])
        ans&=subTreeColor(x,idx,color[x]);
    return ans;
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vii foo;
    REP(i,n-1){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
        foo.pb(mp(v1,v2));
    }
    FOR(i,1,n+1)
        cin>>color[i];
    pi cur=mp(0,0);
    for(auto p : foo)
        if(color[p.F]!=color[p.S]){
            cur=p;
            break;
        }
    if(cur.F){
        if(check(cur.F))
            cout<<"YES"<<endl<<cur.F<<endl;
        else if(check(cur.S))
            cout<<"YES"<<endl<<cur.S<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"YES"<<endl<<1<<endl;
    return 0;
}
