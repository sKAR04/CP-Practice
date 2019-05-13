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
const int MAXN=1e5+10;
//Main function
int main(){
    IOS;
    TIE;

    ll n,m;
    cin>>n>>m;

    ll boys[n],girls[m];
    ll bMax=LLONG_MIN;
    REP(i,n){
        cin>>boys[i];
        bMax=max(bMax,boys[i]);
    }

    ll gMin=LLONG_MAX;
    REP(i,m){
        cin>>girls[i];
        gMin=min(gMin,girls[i]);
    }

    if(gMin<bMax)
        cout<<-1<<endl;
    else{
        ll ans=0LL;
        sort(boys,boys+n);
        sort(girls,girls+m);

        DFOR(i,n-2,0)
            ans+=m*boys[i];
        FOR(i,1,m)
            ans+=girls[i];

        if(girls[0]==boys[n-1])
            ans+=girls[0];
        else{
            ans+=boys[n-1];
            ans-=boys[n-2];
            ans+=girls[0];
        }
        cout<<ans<<endl;
    }

    return 0;
}
