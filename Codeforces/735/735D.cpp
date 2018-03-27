//Strike me down and I shall become stronger, than you can possibly imagine
//Streak Count :
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
bool isPrime(ll n){
    ll root=sqrt(n);
    FOR(i,2,root+1)
        if(!(n%i))
            return false;
    return true;
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll ans=0;
    if(isPrime(n))
        ans=1;
    else if(n%2){
        if(isPrime(n-2))
            ans=2;
        else
            ans=3;
    }
    else
        ans=2;
    cout<<ans<<endl;
    return 0;
}
