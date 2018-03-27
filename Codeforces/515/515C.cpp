
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
vi refVect[10];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    refVect[2]={2};
    refVect[3]={3};
    refVect[4]={2,2,3};
    refVect[5]={5};
    refVect[6]={3,5};
    refVect[7]={7};
    refVect[8]={2,2,2,7};
    refVect[9]={2,3,3,7};
    int n;
    cin>>n;
    string str;
    cin>>str;
    vi ans;
    REP(i,n)
        for(int x : refVect[str[i]-48])
            ans.pb(x);
    sort(ans.rbegin(),ans.rend());
    for(int x : ans)
        cout<<x;
    cout<<endl;
    return 0;
}
