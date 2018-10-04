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
int k,degree[1010];
vi adj[1010];
void buildGraph(int startIdx){
    FOR(i,startIdx+1,startIdx+k+1){
        adj[startIdx].pb(i);
        adj[i].pb(startIdx);

        ++degree[i];
        ++degree[startIdx];
    }

    FOR(i,startIdx+2,startIdx+k+1){
        adj[startIdx+1].pb(i);
        adj[i].pb(startIdx+1);

        ++degree[i];
        ++degree[startIdx+1];
    }

    FOR(i,startIdx+2,startIdx+k+1){
        adj[startIdx+k+1].pb(i);
        adj[i].pb(startIdx+k+1);

        ++degree[i];
        ++degree[startIdx+k+1];
    }

    REP(i,k-1){
        vii v;
        FOR(j,startIdx+2,startIdx+k+1)
            v.pb(mp(degree[j],j));
        sort(all(v));

        for(pi p : v){
            if(degree[v[0].S]==k)
                break;
            if(p.S!=v[0].S){
                ++degree[v[0].S];
                ++degree[p.S];
                adj[v[0].S].pb(p.S);
                adj[p.S].pb(v[0].S);
            }
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>k;
    if(k&1){
        cout<<"YES"<<endl;
        if(k==1){
            cout<<2<<" "<<1<<endl;
            cout<<1<<" "<<2<<endl;
        }
        else{
            buildGraph(1);
            buildGraph(k+3);
            adj[k+2].pb(2*k+4);
            adj[2*k+4].pb(k+2);

            cout<<2*(k+2)<<" "<<k*(k+2)<<endl;
            FOR(i,1,2*k+5)
                for(int v : adj[i])
                    if(v>i)
                        cout<<i<<" "<<v<<endl;
        }
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
