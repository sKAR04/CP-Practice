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
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
ll arr[5010];
ll getMinStrokes(ll l,ll r){
    if(l>r)
        return 0LL;

    ll minVal=LLONG_MAX;
    FOR(i,l,r+1)
        minVal=min(minVal,arr[i]);

    FOR(i,l,r+1)
        arr[i]-=minVal;

    ll curLeft=l-1LL;
    FOR(i,l,r+1)
        if(!arr[i]){
            minVal+=getMinStrokes(curLeft+1LL,i-1LL);
            curLeft=i;
        }
    minVal+=getMinStrokes(curLeft+1,r);
    return min(minVal,r-l+1LL);
}
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;

    REP(i,n)
        cin>>arr[i];
    cout<<getMinStrokes(0LL,n-1LL)<<endl;

    return 0;
}
