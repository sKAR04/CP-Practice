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
    int n,k;
    cin>>n>>k;

    priority_queue<int> s0;
    priority_queue<int,vi,greater<int> > s1;
    REP(i,n){
        int temp;
        cin>>temp;

        if(i & 1)
            s1.push(temp);
        else
            s0.push(temp);
    }
    if(n==1)
        cout<<"NO"<<endl;
    else{
        REP(i,k){
            int foo=s0.top(),bar=s1.top();
            if(foo<=bar)
                break;
            else{
                s0.pop();
                s1.pop();

                s0.push(bar);
                s1.push(foo);
            }
        }

        int sum0=0,sum1=0;
        while(!s0.E){
            sum0+=s0.top();
            s0.pop();
        }

        while(!s1.E){
            sum1+=s1.top();
            s1.pop();
        }

        if(sum1>sum0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
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
