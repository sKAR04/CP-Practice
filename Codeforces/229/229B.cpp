/*
######################################################
#    I don't know what I'm doing with my life O.O    #
######################################################
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
const int MAXN=1e5+10;
ll minDist[MAXN];
vlll adj[MAXN];
vll delays[MAXN];
bool marked[MAXN];
int n,m;

ll getDelay(ll idx,ll val){
    auto it=lower_bound(all(delays[idx]),val);
    if(it==delays[idx].end() || *it!=val)
        return 0LL;
    else{
        ll l=it-delays[idx].begin();
        ll low=l,high=delays[idx].size()-1LL,mid;

        ll ans=0LL;
        while(low<=high){
            mid=(low+high)>>1LL;
            if(delays[idx][mid]==delays[idx][l]+mid-l){
                low=mid+1LL;
                ans=mid-l+1;
            }
            else if(delays[idx][mid]>delays[idx][l]+mid-l)
                high=mid-1LL;
            else
                low=mid+1LL;
        }

        return ans;
    }
}

void dijkstra(){
    FOR(i,1,MAXN)
        minDist[i]=LLONG_MAX;

    PQ<pll,vlll,greater<pll>> q;
    q.push(mp(0,0));

    ll tmp;
    while(!q.E){
        ll cur=q.top().S;
        q.pop();

        marked[cur]=true;
        for(auto ch : adj[cur])
            if(!marked[ch.F]){
                tmp=minDist[cur]+ch.S+getDelay(ch.F,minDist[cur]+ch.S);
                if(tmp<minDist[ch.F]){
                    minDist[ch.F]=tmp;
                    q.push(mp(minDist[ch.F],ch.F));
                }
            }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;

    ll u,v,w;
    REP(i,m){
        cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    adj[0].pb(mp(1,0));

    ll foo,bar;
    FOR(i,1,n){
        cin>>foo;
        REP(j,foo){
            cin>>bar;
            delays[i].pb(bar);
        }
    }

    cin>>foo;
    REP(i,foo)
        cin>>bar;
    dijkstra();

    if(minDist[n]==LLONG_MAX)
        minDist[n]=-1LL;
    cout<<minDist[n]<<endl;

    // FOR(i,1,n+1)
    //     cout<<minDist[i]<<" ";
    // cout<<endl;

    return 0;
}
