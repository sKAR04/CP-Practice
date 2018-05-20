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
int n,m;
char grid[60][60];
bool vis[60][60];
bool flag;
pi cur;

void dfs(pi p,pi parent){
    if(flag)
        return ;

    vis[p.F][p.S]=true;

    pi foo[4]={mp(p.F+1,p.S),mp(p.F-1,p.S),mp(p.F,p.S+1),mp(p.F,p.S-1)};

    REP(i,4)
        if(foo[i].F>-1 && foo[i].S>-1 && foo[i].F<n && foo[i].S<m && grid[p.F][p.S]==grid[foo[i].F][foo[i].S] && foo[i]!=parent){
            if(foo[i]==cur){
                flag=true;
                return ;
            }
            else if(!vis[foo[i].F][foo[i].S])
                dfs(foo[i],p);
        }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;

    REP(i,n)
        REP(j,m)
            cin>>grid[i][j];

    REP(i,n)
        REP(j,m){
            cur=mp(i,j);
            dfs(cur,mp(-1,-1));

            if(flag){
                cout<<"Yes"<<endl;
                return 0;
            }

            REP(i,60)
                REP(j,60)
                    vis[i][j]=false;
        }

    cout<<"No"<<endl;

    return 0;
}
