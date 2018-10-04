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
int idx[10010];
bool isPrime[10010];
vi primes;

vi adj[1100];
void sieve(){
    fill(isPrime,isPrime+10010,true);
    isPrime[0]=isPrime[1]=false;
    idx[0]=-1;

    FOR(i,1,10010){
        idx[i]+=idx[i-1];
        if(isPrime[i]){
            if(i>999 && i<10000){
                ++idx[i];
                primes.pb(i);
            }
            for(int j=2*i;j<10010;j+=i)
                isPrime[j]=false;
        }
    }
}
void precalc(){
    sieve();

    for(int p : primes){
        FOR(i,1,10){
            int temp=p%1000+i*1000;
            if(isPrime[temp]){
                adj[idx[temp]].pb(idx[p]);
                adj[idx[p]].pb(idx[temp]);
            }
        }

        REP(i,10){
            int temp=(p/1000)*1000+i*100+p%100;
            if(isPrime[temp]){
                adj[idx[temp]].pb(idx[p]);
                adj[idx[p]].pb(idx[temp]);
            }
        }

        REP(i,10){
            int temp=(p/100)*100+i*10+p%10;
            if(isPrime[temp]){
                adj[idx[temp]].pb(idx[p]);
                adj[idx[p]].pb(idx[temp]);
            }
        }

        REP(i,10){
            int temp=(p/10)*10+i;
            if(isPrime[temp]){
                adj[idx[temp]].pb(idx[p]);
                adj[idx[p]].pb(idx[temp]);
            }
        }
    }
}

inline void solve(){
    int p1,p2;
    cin>>p1>>p2;

    int dist[1100];
    fill(dist,dist+1100,INF);

    bool vis[1100];
    fill(vis,vis+1100,false);

    qi q;
    q.push(idx[p1]);
    dist[idx[p1]]=0;
    vis[idx[p1]]=true;

    while(!q.E){
        int cur=q.front();

        for(int p : adj[cur])
            if(!vis[p]){
                dist[p]=dist[cur]+1;
                vis[p]=true;
                q.push(p);
            }

        q.pop();
    }

    if(dist[idx[p2]]==INF)
        cout<<"Impossible"<<endl;
    else
        cout<<dist[idx[p2]]<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    precalc();

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
