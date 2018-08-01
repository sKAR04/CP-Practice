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
ll power(ll base,ll exp){
    if(!exp)
        return 1;
    else{
        ll ans=power(base,exp/2);
        ans=(ans*ans)%MOD;
        if(exp & 1LL)
            ans=(ans*base)%MOD;

        return ans;
    }
}

ll gcd(ll a,ll b){
    if(!b)
        return a;
    return gcd(b,a%b);
}

void solve(){
    ll n,k;
    cin>>n>>k;

    ll ans=power(2,n-1LL);
    ans=(ans+MOD-n)%MOD;
    ans=(ans*power(power(2,n-1LL),MOD-2LL))%MOD;
    cout<<ans<<endl;

}
//Main function
int main(){
    IOS;
    TIE;
    /*
    int t;
    cin>>t;

    while(t--)
        solve();
    */
    solve();
    return 0;
}
