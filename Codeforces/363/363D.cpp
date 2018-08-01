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
ll n,m,a;
ll dudes[100010],bikes[100010];

ll len,val;
void bSearch(ll low,ll high){
    ll mid=(low+high)>>1;
    if(low<=high){
        ll moneyLeft=a,tot=0;
        bool flag=true;

        REP(i,mid){
            if(dudes[i]>=bikes[mid-i-1])
                tot+=bikes[mid-i-1];
            else if(dudes[i]+moneyLeft>=bikes[mid-i-1]){
                moneyLeft-=(bikes[mid-i-1]-dudes[i]);
                tot+=dudes[i];
            }
            else{
                flag=false;
                break;
            }
        }

        if(flag){
            len=mid;
            val=(tot-moneyLeft>0)?tot-moneyLeft:0;
            bSearch(mid+1,high);
        }
        else
            bSearch(low,mid-1);
    }
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m>>a;
    REP(i,n)
        cin>>dudes[i];
    REP(i,m)
        cin>>bikes[i];

    sort(dudes,dudes+n,greater<int>());
    sort(bikes,bikes+m);

    bSearch(1,(n>m)?m:n);
    cout<<len<<" "<<val<<endl;

    return 0;
}
