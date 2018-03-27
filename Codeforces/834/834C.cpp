
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
ll binarySearch(ll low,ll high,ll key){
    ll mid=(low+high) >> 1;
    if(low<=high){
        ll cur=mid*mid*mid;
        if(cur==key)
            return mid;
        else if(cur>key)
            return binarySearch(low,mid-1,key);
        else
            return binarySearch(mid+1,high,key);
    }
    else
        return mid;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    REP(i,n){
        ll a,b;
        cin>>a>>b;
        ll root=binarySearch(1LL,1000000LL,a*b);
        if(root*root*root==a*b && a%root==0 && b%root==0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
