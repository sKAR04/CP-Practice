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
#define MOD  998244353LL
#define EPS  0.000000001
#define INF  998244353LL

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
const int MAXN=300010;
vii edges;
vi adj[MAXN];
bool color[MAXN],vis[MAXN];

ll blackCnt,whiteCnt;
void dfs(int cur){
	vis[cur]=true;
	if(color[cur])
		++blackCnt;
	else
		++whiteCnt;

	for(int ch : adj[cur])
		if(!vis[ch]){
			color[ch]=(!color[cur]);
			dfs(ch);
		}
}

ll power(ll base,ll exp){
	if(!exp)
		return 1LL;
	else{
		ll ans=power(base,exp/2LL);
		ans=(ans*ans)%MOD;

		if(exp&1LL)
			ans=(ans*base)%MOD;

		return ans;
	}
}
int cnt;
void solve(){
	int n,m;
	cin>>n>>m;

	REP(i,m){
		int v1,v2;
		cin>>v1>>v2;
		edges.pb(mp(v1,v2));
		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	ll ans=1LL;
	FOR(i,1,n+1)
		if(!vis[i]){
			dfs(i);
			ans=(ans*(power(2LL,blackCnt)+power(2LL,whiteCnt))%MOD)%MOD;
			blackCnt=whiteCnt=0;
		}

	for(pi p : edges)
		if(color[p.F]==color[p.S])
			ans=0LL;
	cout<<ans<<endl;

	edges.clear();
	FOR(i,1,n+1){
		adj[i].clear();
		color[i]=vis[i]=false;
	}
}
//Main function
int main(){
    IOS;
    TIE;

	int t;
	cin>>t;

	REP(i,t)
		solve();

    return 0;
}
