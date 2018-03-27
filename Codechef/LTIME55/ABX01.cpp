
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
ll digitSum(ll x){
    ll sum=0;
    while(x){
        sum+=(x%10LL);
        x/=10LL;
    }
    return sum;
}

ll powerSum(ll x,ll n){
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    ll ans=powerSum(x,n/2);
    while(ans>9)
        ans=digitSum(ans);
    ans*=ans;
    while(ans>9)
        ans=digitSum(ans);
    if(n & 1)
        ans*=digitSum(x);
    while(ans>9)
        ans=digitSum(ans);
    return ans;
}


//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a,n;
        cin>>a>>n;
        while(a>9)
            a=digitSum(a);
        cout<<powerSum(a,n)<<endl;
    }
    return 0;
}
