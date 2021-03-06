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
int arr[100010];
int n,h;

int binarySearch(int low,int high){
    int mid=(low+high) >> 1;
    if(low>=high)
        return mid;
    else{
        int val=0;
        REP(i,n){
            val+=(arr[i]/mid);
            if(arr[i]%mid)
                ++val;
        }

        if(val<=h)
            return binarySearch(low,mid);
        else
            return binarySearch(mid+1,high);
    }
}

void solve(){
    cin>>n>>h;
    REP(i,n)
        cin>>arr[i];

    cout<<binarySearch(1,1000000000)<<endl;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
