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
#define REP(i,n) 	    for(ll i=0;i<(n);++i)
#define FOR(i,a,b)      for(ll i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(ll i=(a);i>=(b);--i)

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
#define scan getFoo

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
pi src,dest;
int curHash=1;
map<pi,int> hashMap;
vi adj[100010];
bool vis[100010];
int minDist[100010];

int bfs(){
    fill(minDist,minDist+100010,INF);
    qi q;

    q.push(hashMap[src]);
    minDist[hashMap[src]]=0;
    vis[hashMap[src]]=true;

    while(!q.E){
        int cur=q.front();
        q.pop();

        for(int x : adj[cur])
            if(!vis[x]){
                minDist[x]=minDist[cur]+1;
                vis[x]=true;
                q.push(x);
            }
    }

    if(minDist[hashMap[dest]]==INF)
        return -1;
    else
        return minDist[hashMap[dest]];
}
//Main function
int main(){
    //IOS;
    //TIE;
    cin>>src.F>>src.S>>dest.F>>dest.S;

    hashMap[src]=curHash++;
    hashMap[dest]=curHash++;

    int m;
    cin>>m;

    REP(i,m){
        int r,a,b;
        cin>>r>>a>>b;

        FOR(j,a,b+1)
            hashMap[mp(r,j)]=curHash++;
    }

    for(auto it=hashMap.begin();it!=hashMap.end();++it){
        pi cur=it->F;
        pi nbr[8]={mp(cur.F-1,cur.S-1),mp(cur.F-1,cur.S),mp(cur.F-1,cur.S+1),mp(cur.F,cur.S-1),mp(cur.F,cur.S+1),mp(cur.F+1,cur.S-1),mp(cur.F+1,cur.S),mp(cur.F+1,cur.S+1)};

        for(pi p : nbr)
            if(hashMap.find(p)!=hashMap.end()){
                adj[it->S].pb(hashMap[p]);
                adj[hashMap[p]].pb(it->S);
            }
    }

    cout<<bfs()<<endl;

    return 0;
}
