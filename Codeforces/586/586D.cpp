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
int n,k;
bool vis[3][110][2];
char grid[3][110];
void dfs(int x,int y,bool flag){
    vis[x][y][flag]=true;
    if(y>=n)
        return ;

    if(!flag){
        if(x && grid[x][y+1]=='.' && grid[x-1][y+1]=='.' && !vis[x-1][y+1][!flag])
            dfs(x-1,y+1,!flag);
        if(x<2 && grid[x][y+1]=='.' && grid[x+1][y+1]=='.' && !vis[x+1][y+1][!flag])
            dfs(x+1,y+1,!flag);
        if(grid[x][y+1]=='.' && !vis[x][y+1][!flag])
            dfs(x,y+1,!flag);
    }
    else{
        if(grid[x][y+1]=='.'){
            vis[x][y+1][flag]=true;
            if(grid[x][y+2]=='.' && !vis[x][y+2][!flag])
                dfs(x,y+2,!flag);
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--){
        REP(i,3)
            REP(j,110)
                vis[i][j][0]=vis[i][j][1]=false;

        cin>>n>>k;
        int x,y;

        REP(i,3)
            FOR(j,1,n+1){
                cin>>grid[i][j];
                if(grid[i][j]=='s')
                    x=i,y=j;
            }
        dfs(x,y,0);

        bool flag=false;
        REP(i,3)
            flag|=(vis[i][n][0] || vis[i][n][1]);

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
