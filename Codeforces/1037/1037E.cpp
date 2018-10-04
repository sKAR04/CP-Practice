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
set<int> adj[200010];
int n,m,k,inCnt[200010];
set<pi> s;

void modSet(){
    while(!s.E){
        int cur=s.begin()->S;
        if(inCnt[cur]<k){
            s.erase(s.begin());
            for(auto it=adj[cur].begin();it!=adj[cur].end();++it){
                s.erase(s.find(mp(inCnt[*it],*it)));
                --inCnt[*it];
                s.insert(mp(inCnt[*it],*it));
                adj[*it].erase(cur);
            }
        }
        else
            break;
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m>>k;

    vii edges;
    REP(i,m){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].insert(v2);
        adj[v2].insert(v1);
        ++inCnt[v1];
        ++inCnt[v2];
        edges.pb(mp(v1,v2));
    }

    FOR(i,1,n+1)
        s.insert(mp(inCnt[i],i));

    di ans;
    while(!edges.E){
        modSet();
        ans.push_front(s.size());

        pi p=edges.back();
        edges.pop_back();
        auto it1=s.find(mp(inCnt[p.F],p.F)),it2=s.find(mp(inCnt[p.S],p.S));
        if(it1!=s.end() && it2!=s.end()){
            if(inCnt[p.F]==k){
                s.erase(s.find(mp(inCnt[p.F],p.F)));
                --inCnt[p.F];
                s.insert(mp(inCnt[p.F],p.F));
            }
            else if(inCnt[p.S]==k){
                s.erase(s.find(mp(inCnt[p.S],p.S)));
                --inCnt[p.S];
                s.insert(mp(inCnt[p.S],p.S));
            }
            else{
                s.erase(s.find(mp(inCnt[p.F],p.F)));
                s.erase(s.find(mp(inCnt[p.S],p.S)));
                --inCnt[p.F];
                --inCnt[p.S];
                s.insert(mp(inCnt[p.F],p.F));
                s.insert(mp(inCnt[p.S],p.S));

                adj[p.F].erase(p.S);
                adj[p.S].erase(p.F);
            }
        }
    }

    for(int x : ans)
        cout<<x<<endl;

    return 0;
}
