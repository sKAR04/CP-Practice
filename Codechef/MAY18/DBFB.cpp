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
ll base[2][2]={{1,0},{0,1}};
ll mul[2][2]={{1,1},{1,0}};
ll fib[2][2];
void multiply(ll a[2][2],ll b[2][2]){
    ll x=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
    ll y=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
    ll z=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
    ll w=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;

    a[0][0]=x;
    a[0][1]=y;
    a[1][0]=z;
    a[1][1]=w;
}

void power(ll exp){
    if(exp){
        power(exp/2);
        multiply(base,base);

        if(exp & 1LL)
            multiply(base,mul);
    }
}

inline void setMatrices(ll foo,ll bar){
    base[0][0]=1;
    base[0][1]=0;
    base[1][0]=0;
    base[1][1]=1;

    fib[0][0]=(foo+bar)%MOD;
    fib[0][1]=bar%MOD;
    fib[1][0]=bar%MOD;
    fib[1][1]=foo%MOD;
}

inline void solve(){
    ll m,n;
    cin>>m>>n;

    ll a[m],b[m];
    REP(i,m)
        cin>>a[i];
    REP(i,m)
        cin>>b[i];

    ll num;
    ll ans=0;
    setMatrices(0,1);
    power(n-1);
    multiply(fib,base);

    num=fib[1][1];
    REP(i,m){
        ans+=(num*(b[i]-b[0])%MOD);
        ans%=MOD;
    }
    ans*=m;
    ans%=MOD;

    REP(i,m){
        setMatrices(a[i],b[0]);
        power(n-1);
        multiply(fib,base);
        ans+=(fib[1][1]*m);
        ans%=MOD;
    }

    cout<<ans<<endl;
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
