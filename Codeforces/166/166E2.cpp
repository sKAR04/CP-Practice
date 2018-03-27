
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
ll base[2][2]={{2,1},{3,0}};
ll mtrx[2][2]={{2,1},{3,0}};
ll ans[2][2]={{6,3},{3,0}};

void multiply(ll mtrx1[2][2],ll mtrx2[2][2]){
    ll x=(mtrx1[0][0]*mtrx2[0][0]+mtrx1[0][1]*mtrx2[1][0])%MOD;
    ll y=(mtrx1[0][0]*mtrx2[0][1]+mtrx1[0][1]*mtrx2[1][1])%MOD;
    ll z=(mtrx1[1][0]*mtrx2[0][0]+mtrx1[1][1]*mtrx2[1][0])%MOD;
    ll w=(mtrx1[1][0]*mtrx2[0][1]+mtrx1[1][1]*mtrx2[1][1])%MOD;
    mtrx1[0][0]=x;
    mtrx1[0][1]=y;
    mtrx1[1][0]=z;
    mtrx1[1][1]=w;
}

void power(ll mtrx[2][2],int n){
    if(n<2)
        return ;
    power(mtrx,n/2);
    multiply(mtrx,mtrx);
    if(n & 1)
        multiply(mtrx,base);
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    if(n==1)
        cout<<0<<endl;
    else if(n==2)
        cout<<3<<endl;
    else if(n==3)
        cout<<6<<endl;
    else{
        power(mtrx,n-3);
        multiply(ans,mtrx);
        cout<<ans[0][0]<<endl;
    }
    return 0;
}
