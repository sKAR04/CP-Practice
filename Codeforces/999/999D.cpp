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

//Main function
int main(){
    IOS;
    TIE;

    ll n,m;
    cin>>n>>m;

    ll arr[n];
    vll rem[m];
    REP(i,n){
        cin>>arr[i];
        rem[arr[i]%m].pb(i);
    }

    dll low,high;
    REP(i,m)
        if(rem[i].size()>n/m)
            high.pb(i);
        else if(rem[i].size()<n/m)
            low.pb(i);

    while(high.size()){
        ll lowTop=low.back(),highTop=high.back();

        if(lowTop<highTop){
            lowTop=low.front();
            while(rem[lowTop].size()<n/m && rem[highTop].size()>n/m){
                rem[lowTop].pb(rem[highTop].back());
                rem[highTop].pop_back();
            }

            if(rem[lowTop].size()==n/m)
                low.pop_front();
            if(rem[highTop].size()==n/m)
                high.pop_back();
        }
        else{
            while(rem[lowTop].size()<n/m && rem[highTop].size()>n/m){
                rem[lowTop].pb(rem[highTop].back());
                rem[highTop].pop_back();
            }

            if(rem[lowTop].size()==n/m)
                low.pop_back();
            if(rem[highTop].size()==n/m)
                high.pop_back();
        }
    }

    ll ans=0;
    REP(i,m)
        for(ll r : rem[i]){
            ll prevVal=arr[r];

            ll add;
            if(arr[r]%m<=i)
                add=(i-arr[r]%m);
            else
                add=(m-arr[r]%m+i);
            ans+=add;
            arr[r]+=add;
        }


    cout<<ans<<endl;
    REP(i,n)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
