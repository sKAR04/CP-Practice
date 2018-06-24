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

    vll arr;
    REP(i,n){
        ll temp;
        cin>>temp;
        arr.pb(temp);
    }
    sort(all(arr));

    vi ans;
    ans.pb(arr[0]);
    REP(i,n){
        bool twoPower[32]={};
        REP(j,32)
            twoPower[j]=binary_search(all(arr),arr[i]+(1LL << j));

        vi temp;
        temp.pb(arr[i]);
        REP(j,31)
            if(twoPower[j] && twoPower[j+1]){
                temp.pb(arr[i]+(1LL << j));
                temp.pb(arr[i]+(1LL << j+1));
                break;
            }

        if(temp.size()==1)
            REP(j,32)
                if(twoPower[j]){
                    temp.pb(arr[i]+(1LL << j));
                    break;
                }

        if(ans.size()<temp.size())
            ans=temp;
    }
    cout<<ans.size()<<endl;
    for(ll x : ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
