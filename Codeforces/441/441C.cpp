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
bool vis[310][310];
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m>>k;

    vii tubes[k];

    string dir="R";
    pi cur=mp(1,1);
    REP(i,k-1)
        REP(j,2){
            tubes[i].pb(cur);
            vis[cur.F][cur.S]=true;
            pi foo[3]={mp(cur.F,cur.S+1),mp(cur.F+1,cur.S),mp(cur.F,cur.S-1)};

            if(dir=="R")
                if(!vis[foo[0].F][foo[0].S] && foo[0].F && foo[0].S && foo[0].F<n+1 && foo[0].S<m+1)
                    cur=foo[0];
                else{
                    dir="U";
                    cur=foo[1];
                }
            else if(dir=="U")
                if(!vis[foo[0].F][foo[0].S] && foo[0].F && foo[0].S && foo[0].F<n+1 && foo[0].S<m+1){
                    dir="R";
                    cur=foo[0];
                }
                else{
                    dir="L";
                    cur=foo[2];
                }
            else
                if(!vis[foo[2].F][foo[2].S] && foo[2].F && foo[2].S && foo[2].F<n+1 && foo[2].S<m+1)
                    cur=foo[2];
                else{
                    dir="U";
                    cur=foo[1];
                }
        }

    REP(j,m*n-2*(k-1)){
        tubes[k-1].pb(cur);
        vis[cur.F][cur.S]=true;
        pi foo[3]={mp(cur.F,cur.S+1),mp(cur.F+1,cur.S),mp(cur.F,cur.S-1)};

        if(dir=="R")
            if(!vis[foo[0].F][foo[0].S] && foo[0].F && foo[0].S && foo[0].F<n+1 && foo[0].S<m+1)
                cur=foo[0];
            else{
                dir="U";
                cur=foo[1];
            }
        else if(dir=="U")
            if(!vis[foo[0].F][foo[0].S] && foo[0].F && foo[0].S && foo[0].F<n+1 && foo[0].S<m+1){
                dir="R";
                cur=foo[0];
            }
            else{
                dir="L";
                cur=foo[2];
            }
        else
            if(!vis[foo[2].F][foo[2].S] && foo[2].F && foo[2].S && foo[2].F<n+1 && foo[2].S<m+1)
                cur=foo[2];
            else{
                dir="U";
                cur=foo[1];
            }
    }

    REP(i,k){
        cout<<tubes[i].size()<<" ";
        for(auto p : tubes[i])
            cout<<p.F<<" "<<p.S<<" ";
        cout<<endl;
    }

    return 0;
}
