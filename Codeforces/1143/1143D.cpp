/*
######################################################
# Let's see where this is going to lead me shall we? #
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
vll burgers,tmp;

ll gcd(ll a,ll b){
    if(!b)
        return a;
    return gcd(b,a%b);
}
//Main function
int main(){
    IOS;
    TIE;

    ll n,k;
    cin>>n>>k;

    FOR(i,1,n+1)
        burgers.pb((i-1)*k+1);

    ll a,b;
    cin>>a>>b;

    ll prod=n*k;
    ++a;
    for(ll x : burgers){
        tmp.pb((x-b+prod)%prod);
        tmp.pb((x+b+prod)%prod);
    }

    ll maxTurns=LLONG_MIN,minTurns=LLONG_MAX;
    for(ll x : tmp){
        ll curTurns=prod/gcd(prod,(x-a+prod)%prod);
        maxTurns=max(maxTurns,curTurns);
        minTurns=min(minTurns,curTurns);
        //cout<<x<<" "<<curTurns<<endl;
    }
    cout<<minTurns<<" "<<maxTurns<<endl;

    return 0;
}
