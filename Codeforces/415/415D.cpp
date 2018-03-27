
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
ll dp[2010][2010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    FOR(i,1,k+1)
        dp[1][i]=1;
    FOR(x,2,n+1){
        vi tempFactors;
        FOR(i,1,x+1)
            if(x%i==0)
                tempFactors.pb(i);
        dp[x][1]=1;
        FOR(i,2,k+1)
            for(int f : tempFactors)
                dp[x][i]=(dp[x][i]+dp[f][i-1])%MOD;
    }
    ll ans=0;
    FOR(i,1,n+1)
        ans=(ans+dp[i][k])%MOD;
    cout<<ans<<endl;
    return 0;
}
