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
int dpUp[1010][1010],dpDown[1010][1010],dpLeft[1010][1010],dpRight[1010][1010];
int sumLeft[1010][1010],sumRight[1010][1010],sumUp[1010][1010],sumDown[1010][1010];
bool possible[1010][1010];
char grid[1010][1010];
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    FOR(i,1,n+1)
        FOR(j,1,m+1)
            cin>>grid[i][j];

    FOR(i,1,n+1)
        FOR(j,1,m+1)
            if(grid[i][j]=='*')
                dpLeft[i][j]=dpLeft[i][j-1]+1;
            else
                dpLeft[i][j]=0;

    FOR(i,1,n+1)
        DFOR(j,m,1)
            if(grid[i][j]=='*')
                dpRight[i][j]=dpRight[i][j+1]+1;
            else
                dpRight[i][j]=0;

    FOR(j,1,m+1)
        FOR(i,1,n+1)
            if(grid[i][j]=='*')
                dpUp[i][j]=dpUp[i-1][j]+1;
            else
                dpUp[i][j]=0;

    FOR(j,1,m+1)
        DFOR(i,n,1)
            if(grid[i][j]=='*')
                dpDown[i][j]=dpDown[i+1][j]+1;
            else
                dpDown[i][j]=0;

    vector<pair<pi,int>> ans;
    FOR(i,1,n+1)
        FOR(j,1,m+1){
            int minVal=min(min(dpUp[i][j],dpDown[i][j]),min(dpLeft[i][j],dpRight[i][j]));
            if(minVal>1){
                ++sumLeft[i][j];
                ++sumRight[i][j];
                ++sumUp[i][j];
                ++sumDown[i][j];

                --sumLeft[i][j-minVal];
                --sumRight[i][j+minVal];
                --sumUp[i-minVal][j];
                --sumDown[i+minVal][j];

                ans.pb(mp(mp(i,j),minVal));
            }
        }

    FOR(i,1,n+1){
        int curSum=0;
        FOR(j,1,m+1){
            curSum+=sumRight[i][j];
            if(curSum)
                possible[i][j]=true;
        }
    }

    FOR(i,1,n+1){
        int curSum=0;
        DFOR(j,m,1){
            curSum+=sumLeft[i][j];
            if(curSum)
                possible[i][j]=true;
        }
    }

    FOR(j,1,m+1){
        int curSum=0;
        FOR(i,1,n+1){
            curSum+=sumDown[i][j];
            if(curSum)
                possible[i][j]=true;
        }
    }

    FOR(j,1,m+1){
        int curSum=0;
        DFOR(i,n,1){
            curSum+=sumUp[i][j];
            if(curSum)
                possible[i][j]=true;
        }
    }

    FOR(i,1,n+1)
        FOR(j,1,m+1)
            if(grid[i][j]=='*' && !possible[i][j]){
                cout<<-1<<endl;
                return 0;
            }

    cout<<ans.size()<<endl;
    for(auto p : ans)
        cout<<p.F.F<<" "<<p.F.S<<" "<<p.S-1<<endl;

    return 0;
}
