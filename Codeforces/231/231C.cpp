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
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF 0X3f3f3f3f

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
ll n,k;
ll arr[100010];
ll sum[100010];

ll binarySearch(ll low,ll high,ll idx,ll x){
    ll mid=(low+high) >> 1;
    if(low<high){
        ll val=x*(idx-mid+1)-sum[mid]+sum[idx+1];
        if(val>k)
            return binarySearch(mid+1,high,idx,x);
        else
            return binarySearch(low,mid-1,idx,x);
    }
    else{
        if(mid<0)
            ++mid;

        return mid;
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>k;

    REP(i,n)
        cin>>arr[i];
    sort(arr,arr+n);

    DFOR(i,n-1,0)
        sum[i]=sum[i+1]+arr[i];

    ll maxOccur=LLONG_MIN;
    ll minNum=LLONG_MAX;
    REP(i,n){
        ll idx=binarySearch(0,i,i,arr[i]);
        ll curOccur=i-idx+1;
        if(arr[i]*(curOccur)+sum[i+1]-sum[idx]>k)
            --curOccur;

        if(curOccur>maxOccur){
            maxOccur=curOccur;
            minNum=arr[i];
        }
        else if(curOccur==maxOccur)
            minNum=min(minNum,arr[i]);
    }
    cout<<maxOccur<<" "<<minNum<<endl;

    return 0;
}
