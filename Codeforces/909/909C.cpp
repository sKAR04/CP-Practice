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
ll dp[5010][5010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    char arr[n];
    REP(i,n)
        cin>>arr[i];
    dp[0][0]=1;
    int prevIdt=0;
    FOR(i,1,n)
        if(arr[i-1]=='f'){
            REP(j,prevIdt+1)
                dp[i][j+1]=dp[i-1][j];
            ++prevIdt;
        }
        else{
            dp[i][prevIdt]=dp[i-1][prevIdt];
            DFOR(j,prevIdt-1,0){
                dp[i][j]=dp[i][j+1]+dp[i-1][j];
                dp[i][j]%=MOD;
            }
        }
    ll ans=0;
    REP(i,prevIdt+1){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
