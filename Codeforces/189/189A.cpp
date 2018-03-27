
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
int dp[4010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,n;
    cin>>n>>a>>b>>c;
    for(int i=a;i<=n;i+=a)
        dp[i]=dp[i-a]+1;
    dp[b]=max(dp[b],1);
    for(int i=b+1;i<=n;++i)
        if(dp[i-b])
            dp[i]=max(dp[i],dp[i-b]+1);
    dp[c]=max(dp[c],1);
    for(int i=c+1;i<=n;++i)
        if(dp[i-c])
            dp[i]=max(dp[i],dp[i-c]+1);
    cout<<dp[n]<<endl;
    return 0;
}
