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
typedef long long ld;

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

//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    pll arr[n];
    REP(i,n)
        cin>>arr[i].F;
    REP(i,n)
        cin>>arr[i].S;

    ll minCost=LLONG_MAX;
    FOR(j,1,n-1){
        ll minIdxX=-1;
        ll minCostX=LLONG_MAX;
        DFOR(i,j-1,0)
            if(arr[i].F<arr[j].F && minCostX>arr[i].S){
                minIdxX=i;
                minCostX=arr[i].S;
            }

        ll minIdxZ=-1;
        ll minCostZ=LLONG_MAX;
        FOR(k,j+1,n)
            if(arr[k].F>arr[j].F && minCostZ>arr[k].S){
                minIdxZ=k;
                minCostZ=arr[k].S;
            }

        if(minIdxX!=-1 && minIdxZ!=-1)
            minCost=min(minCost,minCostX+arr[j].S+minCostZ);
    }
    if(minCost==LLONG_MAX)
        cout<<-1;
    else
        cout<<minCost;
    cout<<endl;

    return 0;
}
