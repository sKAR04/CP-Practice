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
vi adjX[200010],adjY[200010];
bool visX[200010],visY[200010];

void dfs(int cur,bool flag){
    if(!flag){
        visX[cur]=true;
        for(int y : adjX[cur])
            if(!visY[y])
                dfs(y,!flag);
    }
    else{
        visY[cur]=true;
        for(int x : adjY[cur])
            if(!visX[x])
                dfs(x,!flag);
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m,q;
    cin>>n>>m>>q;

    REP(i,q){
        int x,y;
        cin>>x>>y;
        adjX[x].pb(y);
        adjY[y].pb(x);
    }

    int cnt=0;
    FOR(i,1,n+1)
        if(!visX[i]){
            dfs(i,0);
            ++cnt;
        }
    FOR(i,1,m+1)
        if(!visY[i]){
            dfs(i,1);
            ++cnt;
        }
        
    cout<<cnt-1<<endl;

    return 0;
}
