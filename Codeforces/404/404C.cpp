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
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int n,k;
int maxDist;
vii edges;
int edgeCnt[100010];
vi d[100010];

bool getEdges(){
    if(d[0].size()>1)
        return false;
    else{
        FOR(i,1,maxDist+1){
            for(int v : d[i]){
                while(!d[i-1].E && edgeCnt[d[i-1].back()]>=k)
                    d[i-1].pop_back();

                if(d[i-1].E)
                    return false;

                int parent=d[i-1].back();
                ++edgeCnt[parent];
                ++edgeCnt[v];
                edges.pb(mp(parent,v));
            }
        }

        return true;
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>k;

    FOR(i,1,n+1){
        int dist;
        cin>>dist;
        d[dist].pb(i);
        maxDist=max(maxDist,dist);
    }

    if(getEdges()){
        cout<<edges.size()<<endl;
        for(pi p : edges)
            cout<<p.F<<" "<<p.S<<endl;
    }
    else
        cout<<-1<<endl;

    return 0;
}
