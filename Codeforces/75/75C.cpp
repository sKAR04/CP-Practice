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
ll gcd(ll a,ll b){
    if(!b)
        return a;
    return gcd(b,a%b);
}

vll factors;

ll bSearch(ll low,ll high,ll key){
    ll mid=(low+high) >> 1;
    if(low<=high)
        if(factors[mid]>key)
            return bSearch(low,mid-1,key);
        else if(factors[mid]==key)
            return mid;
        else
            return bSearch(mid+1,high,key);
    else
        return mid;
}
//Main function
int main(){
    IOS;
    TIE;

    ll a,b;
    cin>>a>>b;

    ll temp=gcd(a,b);
    ll root=sqrt(temp);
    set<ll> s;
    FOR(i,1,root+1)
        if(temp%i==0){
            s.insert(i);
            s.insert(temp/i);
        }

    for(auto it=s.begin();it!=s.end();++it)
        factors.pb(*it);

    ll n;
    cin>>n;
    while(n--){
        ll l,r;
        cin>>l>>r;

        ll idx=bSearch(0LL,ll(factors.size()-1),r);
        if(factors[idx]<l)
            cout<<-1;
        else
            cout<<factors[idx];
        cout<<endl;
    }

    return 0;
}
