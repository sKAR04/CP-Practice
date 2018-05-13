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
void solve(){
    int n,m;
    cin>>n>>m;

    vi adj[n+1];
    REP(i,m){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    int minDist[n+1];
    fill(minDist,minDist+n+1,INT_MAX);

    int s;
    cin>>s;
    minDist[s]=0;

    qi q;
    q.push(s);

    while(!q.E){
        int cur=q.front();
        q.pop();

        for(auto x : adj[cur])
            if(minDist[x]>minDist[cur]+1){
                minDist[x]=minDist[cur]+1;
                q.push(x);
            }
    }

    FOR(i,1,n+1)
        if(minDist[i])
            if(minDist[i]==INT_MAX)
                cout<<-1<<" ";
            else
                cout<<minDist[i]*6<<" ";
    cout<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
