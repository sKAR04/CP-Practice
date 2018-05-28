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
bool check(ll foo){
    return (foo%3==0 && foo>=0);
}
bool isValid(ll n,ll k,ll d1,ll d2){
    if(n%3LL)
        return false;

    ll x,y,z;
    //xzy
    x=(k+2*d1-d2)/3;
    y=(k-d1-d2)/3;
    z=(k-d1+2*d2)/3;

    if(x<=n/3 && y<=n/3 && z<=n/3 && check(k+2*d1-d2) && check(k-d1-d2) && check(k-d1+2*d2))
        return true;

    //yxz
    x=(k-2*d1+d2)/3;
    y=(k+d1+d2)/3;
    z=(k+d1-2*d2)/3;

    if(x<=n/3 && y<=n/3 && z<=n/3 && check(k-2*d1+d2) && check(k+d1+d2) && check(k+d1-2*d2))
        return true;

    //xyz
    x=(k+2*d1+d2)/3;
    y=(k-d1+d2)/3;
    z=(k-d1-2*d2)/3;

    if(x<=n/3 && y<=n/3 && z<=n/3 && check(k+2*d1+d2) && check(k-d1+d2) && check(k-d1-2*d2))
        return true;

    //zyx
    x=(k-2*d1-d2)/3;
    y=(k+d1-d2)/3;
    z=(k+d1+2*d2)/3;

    if(x<=n/3 && y<=n/3 && z<=n/3 && check(k-2*d1-d2) && check(k+d1-d2) && check(k+d1+2*d2))
        return true;

    return false;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--){
        ll n,k,d1,d2;
        cin>>n>>k>>d1>>d2;

        if(isValid(n,k,d1,d2))
            cout<<"yes";
        else
            cout<<"no";
        cout<<endl;
    }

    return 0;
}
