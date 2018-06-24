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

    int n;
    cin>>n;

    vector<pair<pi,int> > v;
    REP(i,n){
        int m;
        cin>>m;

        int sum=0;
        int arr[m];
        REP(j,m){
            cin>>arr[j];
            sum+=arr[j];
        }

        REP(j,m)
            v.pb(mp(mp(sum-arr[j],i),j));
    }
    sort(all(v));

    int len=v.size();
    REP(i,len-1)
        if(v[i].F.F==v[i+1].F.F && v[i].F.S!=v[i+1].F.S){
            cout<<"YES"<<endl;
            cout<<v[i].F.S+1<<" "<<v[i].S+1<<endl;
            cout<<v[i+1].F.S+1<<" "<<v[i+1].S+1<<endl;
            return 0;
        }

    cout<<"NO"<<endl;
    return 0;
}
