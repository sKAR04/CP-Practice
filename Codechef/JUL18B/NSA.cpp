//Strike me down and I shall become stronger, than you can possibly imagine

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
#define pf push_front

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Variables and Functions required
void solve(){
    string str;
    cin>>str;

    vi l(26,0),r(26,0);
    int len=str.length();

    REP(i,len)
        ++r[str[i]-97];

    ll minDiff=0;
    REP(i,len){
        --r[str[i]-97];
        ll lSum=0,rSum=len-i-1;
        ll curVal=INF,curMinVal=INF;
        REP(j,26){
            if(j)
                lSum+=l[j-1];
            rSum-=r[j];

            curMinVal=min(curMinVal,lSum+rSum+abs(97+j-str[i]));
            if(97+j==str[i])
                curVal=lSum+rSum;
        }
        minDiff=min(minDiff,curMinVal-curVal);
        ++l[str[i]-97];
    }

    ll ans=0;
    REP(i,len){
        DFOR(j,25,str[i]-96)
            ans+=l[j];
        --l[str[i]-97];
    }
    cout<<ans+minDiff<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
