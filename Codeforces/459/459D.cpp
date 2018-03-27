
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
int n;
map<int,int> lCnt,rCnt;
int dp[1000010][2];
int BIT[1000010],arr[1000010];

void updateTree(int idx){
    while(idx<=n){
        ++BIT[idx];
        idx+=(idx & -idx);
    }
}

int queryTree(int idx){
    int sum=0;
    while(idx){
        sum+=BIT[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    REP(i,n)
        cin>>arr[i];
    REP(i,n){
        ++lCnt[arr[i]];
        dp[i][0]=lCnt[arr[i]];
    }
    DFOR(i,n-1,0){
        ++rCnt[arr[i]];
        dp[i][1]=rCnt[arr[i]];
    }
    ll ans=0;
    DFOR(i,n-1,0){
        ans+=(queryTree(dp[i][0]-1));
        updateTree(dp[i][1]);
    }
    cout<<ans<<endl;
    return 0;
}
