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
#define EPS  0.000001

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
void solve(){
    int n;
    long double s,y;
    cin>>n>>s>>y;

    long double vel[n];
    REP(i,n)
        cin>>vel[i];

    bool dir[n];
    REP(i,n)
        cin>>dir[i];

    long double pos[n];
    REP(i,n)
        cin>>pos[i];

    long double len[n];
    REP(i,n)
        cin>>len[i];

    long double curTime=0;
    long double crossTime=y/s;
    REP(i,n)
        if(dir[i]){
            pos[i]+=(curTime*vel[i]);
            if((pos[i]+crossTime*vel[i]<0 && abs(pos[i]+crossTime*vel[i])>=EPS) || (pos[i]>=len[i] && pos[i]>0))
                curTime+=crossTime;
            else
                curTime+=(crossTime+(len[i]-pos[i])/vel[i]);
        }
        else{
            pos[i]-=(curTime*vel[i]);
            if((abs(pos[i])>=len[i] && pos[i]<0) || (pos[i]-crossTime*vel[i]>=EPS && pos[i]-crossTime*vel[i]>0))
                curTime+=crossTime;
            else
                curTime+=(crossTime+(len[i]+pos[i])/vel[i]);
        }

    cout<<setprecision(15)<<curTime<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}
