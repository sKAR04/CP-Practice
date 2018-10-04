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

//Main function
int main(){
    IOS;
    TIE;

    int n,k;
    cin>>n>>k;

    int arr[n];
    REP(i,n)
        cin>>arr[i];

    map<pll,ll> cntMap;
    REP(i,n){
        ll rem=arr[i]%k;
        REP(i,11){
            ++cntMap[mp(rem,i)];
            rem=(rem*10)%k;
        }
    }

    ll cnt=0;
    REP(i,n){
        ll rem=arr[i]%k;

        ll digits;
        REP(j,11){
            if(!arr[i]){
                digits=j;
                break;
            }
            arr[i]/=10;
        }
        cnt+=cntMap[mp((k-rem)%k,digits)];

        ll temp=rem;
        REP(j,digits)
            rem=(rem*10)%k;

        if(!((temp+rem)%k))
            --cnt;
    }
    cout<<cnt<<endl;

    return 0;
}
