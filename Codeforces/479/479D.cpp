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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)

//Main function
int main(){
    IOS;
    TIE;

    ll n,l,x,y;
    cin>>n>>l>>x>>y;

    vll v;
    REP(i,n){
        ll temp;
        cin>>temp;
        v.pb(temp);
    }

    bool flag1=false,flag2=false;
    REP(i,n){
        if(binary_search(all(v),v[i]-x) || binary_search(all(v),v[i]+x))
            flag1=true;
        if(binary_search(all(v),v[i]-y) || binary_search(all(v),v[i]+y))
            flag2=true;
    }

    if(flag1 && flag2)
        cout<<0<<endl;
    else if(flag1)
        cout<<1<<endl<<y<<endl;
    else if(flag2)
        cout<<1<<endl<<x<<endl;
    else{
        REP(i,n){
            ll foo=v[i]-x;
            ll bar=v[i]+x;
            if(foo>0 && foo<l && (binary_search(all(v),foo+y) || binary_search(all(v),foo-y))){
                cout<<1<<endl<<foo<<endl;
                return 0;
            }
            if(bar>0 && bar<l && (binary_search(all(v),bar+y) || binary_search(all(v),bar-y))){
                cout<<1<<endl<<bar<<endl;
                return 0;
            }

            foo=v[i]-y;
            bar=v[i]+y;
            if(foo>0 && foo<l && (binary_search(all(v),foo+x) || binary_search(all(v),foo-x))){
                cout<<1<<endl<<foo<<endl;
                return 0;
            }
            if(bar>0 && bar<l && (binary_search(all(v),bar+x) || binary_search(all(v),bar-x))){
                cout<<1<<endl<<bar<<endl;
                return 0;
            }
        }

        cout<<2<<endl<<x<<endl<<y<<endl;
    }

    return 0;
}
