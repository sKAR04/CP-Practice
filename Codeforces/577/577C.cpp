
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
bool isPrime[1010];
vi primes;
void sieve(){
    fill(isPrime,isPrime+1010,true);
    isPrime[0]=isPrime[1]=false;
    REP(i,1010)
        if(isPrime[i]){
            primes.pb(i);
            for(int j=2*i;j<1010;j+=i)
                isPrime[j]=false;
        }
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    sieve();
    vi ans;
    for(int p : primes){
        int temp=p;
        while(temp<=n){
            ans.pb(temp);
            temp*=p;
        }
    }
    cout<<ans.size()<<endl;
    for(int x : ans)
        cout<<x<<" ";

    cout<<endl;
    return 0;
}
