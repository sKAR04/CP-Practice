//Strike me down and I shall become stronger, than you can possibly imagine

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
#define pf push_front

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Variables and Functions required
vi adj[100010];
int cost[100010];
bool vis[100010];

int dfs(int cur){
    vis[cur]=true;
    int ans=cost[cur];
    for(int v : adj[cur])
        if(!vis[v])
            ans=min(ans,dfs(v));
    return ans;
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

    FOR(i,1,n+1){
        cin>>cost[i];
        if(cost[i]<0)
            cost[i]=INF;
    }

    int sum=0,maxVal=0,minVal=INF,cnt=0;
    FOR(i,1,n+1){
        if(!vis[i]){
            ++cnt;
            int tempMin=dfs(i);
            sum+=tempMin;
            maxVal=(maxVal>tempMin)?maxVal:tempMin;
            minVal=(minVal>tempMin)?tempMin:minVal;
        }
    }
    sum+=(cnt-2)*minVal;

    if(cnt==1)
        cout<<0<<endl;
    else if(maxVal==INF)
        cout<<-1<<endl;
    else
        cout<<sum<<endl;

    return 0;
}
