
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
int n,m,k;
map<pair<int,int>,pair<int,int> > dp;
map<pair<int,int>,int> val;
char museum[1010][1010];
bool vis[1010][1010];
pi curPair;
int maxCnt;

bool check(pi p){
    if(p.F>=1 && p.F<=n && p.S>=1 && p.S<=m && !vis[p.F][p.S]){
        if(museum[p.F][p.S]=='*'){
            ++maxCnt;
            return false;
        }
        else
            return true;
    }
    else
        return false;
}

void dfs(pi p){
    vis[p.F][p.S]=true;
    vii foo={mp(p.F+1,p.S),mp(p.F-1,p.S),mp(p.F,p.S+1),mp(p.F,p.S-1)};
    for(auto x : foo)
        if(check(x)){
            dp[x]=curPair;
            dfs(x);
        }
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    FOR(i,1,n+1)
        FOR(j,1,m+1)
            cin>>museum[i][j];
    while(k--){
        cin>>curPair.F>>curPair.S;
        if(!vis[curPair.F][curPair.S]){
            dp[curPair]=curPair;
            dfs(curPair);
            val[curPair]=maxCnt;
            maxCnt=0;
        }
        cout<<val[dp[curPair]]<<endl;
    }
    return 0;
}
