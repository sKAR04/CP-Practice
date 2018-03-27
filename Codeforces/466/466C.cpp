
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
ll arr[500010],dp[500010],factCnt[500010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    ll sum=0;
    REP(i,n){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%3)
        cout<<0<<endl;
    else if(!sum){
        ll curSum=0;
        REP(i,n-1){
            curSum+=arr[i];
            if(!curSum)
                factCnt[i]=1;
        }
        ll prevVal=0;
        REP(i,n){
            if(factCnt[i])
                ++prevVal;
            dp[i]=prevVal;
        }
        ll ans=0;
        REP(i,n)
            if(factCnt[i])
                ans+=(dp[n-1]-dp[i]);
        cout<<ans<<endl;
    }
    else{
        sum/=3;
        ll curSum=0;
        REP(i,n-1){
            curSum+=arr[i];
            if(curSum==sum)
                factCnt[i]=1;
            else if(curSum==2*sum)
                factCnt[i]=2;
        }
        ll prevVal=0;
        REP(i,n){
            if(factCnt[i]==2)
                ++prevVal;
            dp[i]=prevVal;
        }
        ll ans=0;
        REP(i,n)
            if(factCnt[i]==1)
                ans+=(dp[n-1]-dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}
