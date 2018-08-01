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
ll nCr[5010][5010];
ll arr[5010];

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

void solve(){
    ll n,k;
    cin>>n>>k;

    FOR(i,1,n+1)
        cin>>arr[i];
    sort(arr+1,arr+n+1);

    ll ans=1LL;
    FOR(i,1,n+1)
        ans=(ans*power(arr[i],nCr[n-1][k-1]))%MOD;

    FOR(i,1,n+1){
        if(i>=k)
            ans=(ans*power(power(arr[i],nCr[i-1][k-1]),MOD-2LL))%MOD;
        if(n-i+1>=k)
            ans=(ans*power(power(arr[i],nCr[n-i][k-1]),MOD-2LL))%MOD;
    }
    cout<<ans<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    REP(i,5010)
        nCr[i][0]=1;

    FOR(i,1,5010)
        FOR(j,1,5010)
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%(MOD-1);

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
