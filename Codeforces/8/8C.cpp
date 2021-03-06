/*
#####################################################
# I wi win.. maybe not immediately but definitely #
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
#define a(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007
#define EPS  0.000000001
#define INF  0x3f3f3f3f

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

//vectors
#define vi vector<int>
#define v vector<>
#define vii vector<pair<int,int> >
#define pb 	push_back

//pairs
#define pi pair<int,int>
#define p pair<,>
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

//Declare a variables and methods needed between this comment and the next one(OCD lol)
int dist[30][30];
int path[1 << 24];
//Main function
int main(){
    IOS;
    TIE;

    pi handbag;
    cin>>handbag.F>>handbag.S;

    int n;
    cin>>n;

    vector<pair<int,int> > objects;
    REP(i,n){
        pi object;
        cin>>object.F>>object.S;
        objects.pb(object);
    }
    objects.pb(handbag);

    REP(i,n+1)
        REP(j,n+1)
            dist[i][j]=(objects[i].F-objects[j].F)*(objects[i].F-objects[j].F)+(objects[i].S-objects[j].S)*(objects[i].S-objects[j].S);

    int dp[1 << n];
    REP(i,(1 << n))
        dp[i]=INF;
    dp[0]=0;

    REP(mask,(1 << n))
        if(dp[mask]<INF)
            REP(i,n)
                if(!(mask & (1 << i))){
                    FOR(j,i,n)
                        if(!(mask & (1 << j)))
                            if(dp[mask | (1 << i) | (1 << j)]>dp[mask]+dist[n][i]+dist[i][j]+dist[j][n]){
                                dp[mask | (1 << i) | (1 << j)]=dp[mask]+dist[n][i]+dist[i][j]+dist[j][n];
                                path[mask | (1 << i) | (1 << j)]=mask;
                            }
                    break;
                }
    cout<<dp[(1 << n)-1]<<endl;

    int mask=(1 << n)-1;
    cout<<0<<" ";
    for(int i=(1<<n)-1;i;i=path[i]){
        for(int j=i^path[i];j;j-=j&-j)
            cout<<int(log(j&-j)/log(2)+1e-8+1)<<" ";
        cout<<0<<" ";
    }

    return 0;
}
