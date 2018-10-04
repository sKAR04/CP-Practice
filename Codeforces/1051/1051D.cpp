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
#define MOD  998244353
#define EPS  0.000000001
#define INF  0X3f3f3f3f

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
const int MAXN=1010;
int dp[MAXN][4][2*MAXN];
//Main function
int main(){
    IOS;
    TIE;

    int n,k;
    cin>>n>>k;

    dp[1][0][1]=dp[1][3][1]=1;
    dp[1][1][2]=dp[1][2][2]=1;

    FOR(i,1,n)
        FOR(j,1,k+1)
            REP(x,4)
                REP(y,4)
                    if(x==y){
                        dp[i+1][y][j]+=dp[i][x][j];
                        if(dp[i+1][y][j]>=MOD)
                            dp[i+1][y][j]-=MOD;
                    }
                    else if((x==2 && y==1) || (x==1 && y==2)){
                        dp[i+1][y][j+2]+=dp[i][x][j];
                        if(dp[i+1][y][j+2]>=MOD)
                            dp[i+1][y][j+2]-=MOD;
                    }
                    else if(x==0 || x==3){
                        dp[i+1][y][j+1]+=dp[i][x][j];
                        if(dp[i+1][y][j+1]>=MOD)
                            dp[i+1][y][j+1]-=MOD;
                    }
                    else{
                        dp[i+1][y][j]+=dp[i][x][j];
                        if(dp[i+1][y][j]>=MOD)
                            dp[i+1][y][j]-=MOD;
                    }

    int ans=0;
    REP(i,4){
        ans+=dp[n][i][k];
        if(ans>=MOD)
            ans-=MOD;
    }
    cout<<ans<<endl;

    return 0;
}
