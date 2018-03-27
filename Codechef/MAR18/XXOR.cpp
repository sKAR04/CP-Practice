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
int arr[100010][31];

inline void solve(){
    int n,q;
    cin>>n>>q;

    FOR(i,1,n+1){
        int temp;
        cin>>temp;
        DFOR(j,30,0){
            arr[i][j]=arr[i-1][j]+temp%2;
            temp >>= 1;
        }
    }

    REP(i,q){
        int l,r;
        cin>>l>>r;

        int ans=0;
        REP(j,31){
            ans <<= 1;
            if(arr[r][j]-arr[l-1][j]<(r-l)/2+1)
                ++ans;
        }

        cout<<ans<<endl;
    }
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
