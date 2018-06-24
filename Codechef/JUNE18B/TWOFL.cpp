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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int n,m;
int grid[2010][2010];
set<int> done[2010][2010];
bool vis[2010][2010];

void dfsOneColor(int x,int y,vii &reachable){
    vis[x][y]=true;
    reachable.pb(mp(x,y));

    pi foo[]={mp(x+1,y),mp(x-1,y),mp(x,y+1),mp(x,y-1)};
    REP(i,4)
        if(foo[i].F>-1 && foo[i].F<n && foo[i].S>-1 && foo[i].S<m && !vis[foo[i].F][foo[i].S] && grid[foo[i].F][foo[i].S]==grid[x][y])
            dfsOneColor(foo[i].F,foo[i].S,reachable);
}

void dfsTwoColors(int x,int y,int color1,int color2,vii &reachable){
    vis[x][y]=true;
    reachable.pb(mp(x,y));

    pi foo[]={mp(x+1,y),mp(x-1,y),mp(x,y+1),mp(x,y-1)};
    REP(i,4)
        if(foo[i].F>-1 && foo[i].F<n && foo[i].S>-1 && foo[i].S<m && !vis[foo[i].F][foo[i].S] && (grid[foo[i].F][foo[i].S]==color1 || grid[foo[i].F][foo[i].S]==color2))
            dfsTwoColors(foo[i].F,foo[i].S,color1,color2,reachable);
}

//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;
    REP(i,n)
        REP(j,m)
            cin>>grid[i][j];

    int maxCnt=0;
    REP(i,n)
        REP(j,m)
            if(!vis[i][j]){
                vii reachable;
                dfsOneColor(i,j,reachable);

                set<int> colors;
                for(pi p : reachable){
                    int x=p.F;
                    int y=p.S;

                    vis[x][y]=false;
                    pi foo[]={mp(x+1,y),mp(x-1,y),mp(x,y+1),mp(x,y-1)};
                    REP(i,4)
                        if(foo[i].F>-1 && foo[i].F<n && foo[i].S>-1 && foo[i].S<m)
                            colors.insert(grid[foo[i].F][foo[i].S]);
                }

                for(auto it=colors.begin();it!=colors.end();++it)
                    if(done[i][j].find(*it)==done[i][j].end()){
                        vii temp;
                        dfsTwoColors(i,j,grid[i][j],*it,temp);
                        maxCnt=max(maxCnt,(int)temp.size());

                        for(pi p : temp){
                            if(grid[p.F][p.S]==grid[i][j])
                                done[p.F][p.S].insert(*it);
                            else
                                done[p.F][p.S].insert(grid[i][j]);
                            vis[p.F][p.S]=false;
                        }
                    }

                for(pi p : reachable)
                    vis[p.F][p.S]=true;
            }
    cout<<maxCnt<<endl;

    return 0;
}
