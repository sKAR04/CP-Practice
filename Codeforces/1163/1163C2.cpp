/*
######################################################
#    I don't know what I'm doing with my life O.O    #
######################################################
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
const int MAXN=0;
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    pi p[n];
    REP(i,n)
        cin>>p[i].F>>p[i].S;

    map<pi,set<int>> slopeCnt;

    int num,denom,g;
    REP(i,n)
        FOR(j,i+1,n){
            num=p[i].S-p[j].S;
            denom=p[i].F-p[j].F;

            if(!denom)
                num=1;
            else if(!num)
                denom=1;
            else{
                g=__gcd(abs(num),abs(denom));
                if(denom<0){
                    num*=-1;
                    denom*=-1;
                }
                num/=g;
                denom/=g;
            }
            slopeCnt[mp(num,denom)].insert(denom*p[i].S-num*p[i].F);
        }

    ll tot=0,ans=0;
    for(auto it=slopeCnt.begin();it!=slopeCnt.end();++it)
        tot+=(it->S.size());
    for(auto it=slopeCnt.begin();it!=slopeCnt.end();++it)
        ans+=ll(it->S.size())*ll(tot-it->S.size());
    cout<<ans/2LL<<endl;

    return 0;
}
