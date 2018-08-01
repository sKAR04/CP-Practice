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
ll n,m,w;
ll ans;
ll arr[100010];
ll sum[200010]={};
void binarySearch(ll low,ll high){
    ll mid=(low+high) >> 1;
    if(low<=high){
        fill(sum,sum+200010,0LL);
        ll curSum=0,cnt=0LL;
        REP(i,n){
            curSum+=sum[i];
            if(curSum+arr[i]<mid){
                cnt+=(mid-(curSum+arr[i]));
                sum[i]+=(mid-(curSum+arr[i]));
                sum[i+w]-=(mid-(curSum+arr[i]));
                curSum+=(mid-(curSum+arr[i]));
            }
        }

        if(cnt<=m){
            curSum=0LL;
            ll curMin=LLONG_MAX;
            REP(i,n){
                curSum+=sum[i];
                curMin=min(curMin,curSum+arr[i]);
            }
            ans=max(ans,curMin);
            binarySearch(mid+1LL,high);
        }
        else
            binarySearch(low,mid-1LL);
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m>>w;
    REP(i,n)
        cin>>arr[i];

    binarySearch(1LL,10000000000LL);
    cout<<ans<<endl;

    return 0;
}
