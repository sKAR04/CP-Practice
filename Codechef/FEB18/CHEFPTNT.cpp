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
inline void solve(){
    int n,m,x,k;
    cin>>n>>m>>x>>k;
    int evenCnt=0,oddCnt=0;
    string str;
    cin>>str;
    REP(i,k){
        if(str[i]=='E')
            ++evenCnt;
        else
            ++oddCnt;
    }
    FOR(i,1,m+1){
        if(i & 1){
            n-=min(oddCnt,x);
            oddCnt-=min(oddCnt,x);
        }
        else{
            n-=min(evenCnt,x);
            evenCnt-=min(evenCnt,x);
        }
    }
    if(n<=0)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
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
