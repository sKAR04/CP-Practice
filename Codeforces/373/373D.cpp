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
ll hor[50][50],dp[50][50][50][50];
//Main function
int main(){
    IOS;
    TIE;

    int n,m,q;
    cin>>n>>m>>q;

    FOR(i,1,n+1){
        string str;
        cin>>str;
        FOR(j,1,m+1)
            hor[i][j]=(str[j-1]-48)?0:hor[i][j-1]+1;
    }

    FOR(a,1,n+1)
        FOR(b,1,m+1)
            FOR(c,a,n+1)
                FOR(d,b,m+1){
                    if(c>a)
                        dp[a][b][c][d]+=dp[a][b][c-1][d];
                    if(d>b)
                        dp[a][b][c][d]+=dp[a][b][c][d-1];
                    if(c>a && d>b)
                        dp[a][b][c][d]-=dp[a][b][c-1][d-1];

                    ll curMin=(hor[c][d]>d-b+1)?d-b+1:hor[c][d],curHor=c;
                    while(curMin && curHor>=a){
                        dp[a][b][c][d]+=curMin;
                        --curHor;
                        curMin=(curMin>hor[curHor][d])?hor[curHor][d]:curMin;
                    }
                }

    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<dp[a][b][c][d]<<endl;
    }

    return 0;
}
