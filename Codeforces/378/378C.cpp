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
int n,m,k;
char grid[510][510];
bool vis[510][510];

int remCnt;

void dfs(pi p){
    if(!remCnt)
        return ;

    --remCnt;
    vis[p.F][p.S]=true;

    pi foo[4]={mp(p.F+1,p.S),mp(p.F-1,p.S),mp(p.F,p.S+1),mp(p.F,p.S-1)};
    REP(i,4)
        if(foo[i].F && foo[i].F<=n && foo[i].S && foo[i].S<=m && grid[foo[i].F][foo[i].S]!='#' && !vis[foo[i].F][foo[i].S])
            dfs(foo[i]);
}

//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m>>k;

    pi startPair;
    int freeCnt=0;
    FOR(i,1,n+1)
        FOR(j,1,m+1){
            cin>>grid[i][j];
            if(grid[i][j]!='#'){
                ++freeCnt;
                startPair=mp(i,j);
            }
        }
    remCnt=freeCnt-k;

    dfs(startPair);

    FOR(i,1,n+1){
        FOR(j,1,m+1)
            if(grid[i][j]=='#')
                cout<<"#";
            else if(!vis[i][j])
                cout<<"X";
            else
                cout<<".";

        cout<<endl;
    }

    return 0;
}
