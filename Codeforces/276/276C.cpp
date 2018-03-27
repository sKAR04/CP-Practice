
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
ll temp[1000010],query[1000010],arr[1000010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    FOR(i,1,n+1)
        cin>>arr[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        ++temp[l];
        --temp[r+1];
    }
    ll sum=0;
    REP(i,n+1){
        sum+=temp[i];
        query[i]=sum;
    }
    sort(query,query+n+1);
    sort(arr,arr+n+1);
    ll ans=0;
    REP(i,n+1)
        ans+=(query[i]*arr[i]);
    cout<<ans<<endl;
    return 0;
}
