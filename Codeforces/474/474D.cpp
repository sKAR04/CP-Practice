
//Strike me down and I shall become stronger, than you can possibly imagine

#include <bits/stdc++.h>
using namespace std;

//save time
#define endl '\n'
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001

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

//general
#define E empty()

//Variables and Functions required
int dp[100010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,k;
    cin>>t>>k;
    REP(i,k)
        dp[i]=1;
    FOR(i,k,100010){
        dp[i]=dp[i-1]+dp[i-k];
        dp[i]%=MOD;
    }
    ll sum=0;
    REP(i,100010){
        sum+=dp[i];
        sum%=MOD;
        dp[i]=sum;
    }
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+MOD)%MOD<<endl;
    }
    return 0;
}
