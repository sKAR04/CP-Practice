
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
ll n,k;
ll getMaxSum(ll *arr,ll curSum){
    ll curMax=LLONG_MIN;
    REP(i,n){
        curSum=max(curSum+arr[i],arr[i]);
        curMax=max(curMax,curSum);
    }
    return curMax;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll arr[n];
        REP(i,n)
            cin>>arr[i];
        if(k==1)
            cout<<getMaxSum(arr,0LL)<<endl;
        else{
            ll curSum=0LL,totSum=0;
            REP(i,n){
                curSum=max(curSum+arr[i],arr[i]);
                totSum+=arr[i];
            }
            curSum=max(curSum,(k-2)*totSum+curSum);
            curSum=max(curSum,0LL);
            cout<<getMaxSum(arr,curSum)<<endl;
        }
    }
    return 0;
}
