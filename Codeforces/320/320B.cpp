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
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int len;
vii intervals;
bool vis[110];
map<pi,vector<pair<pi,int> > > adj;

bool dfs(int idx){
    vis[idx]=true;

    for(auto x : adj[intervals[idx]])
        if(!vis[x.S])
            dfs(x.S);
}

//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    REP(i,n){
        int c,l,r;
        cin>>c>>l>>r;
        if(c==1){
            pi cur=mp(l,r);
            REP(i,len){
                if((intervals[i].F<l && l<intervals[i].S) || (intervals[i].F<r && r<intervals[i].S))
                    adj[cur].pb(mp(intervals[i],i));
                if((l<intervals[i].F && intervals[i].F<r) || (l<intervals[i].S && intervals[i].S<r))
                    adj[intervals[i]].pb(mp(cur,len));
            }

            ++len;
            intervals.pb(cur);
        }
        else{
            dfs(l-1);

            if(vis[r-1])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

            fill(vis,vis+110,false);
        }
    }

    return 0;
}
