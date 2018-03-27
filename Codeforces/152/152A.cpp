
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
int marks[110][110];
bool successful[110];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    REP(i,n)
        REP(j,m){
            char temp;
            cin>>temp;
            marks[i][j]=temp-48;
        }
    REP(j,m){
        vii foo;
        REP(i,n)
            foo.pb(mp(marks[i][j],i));
        sort(foo.rbegin(),foo.rend());
        REP(i,n)
            if(foo[i].F==foo[0].F)
                successful[foo[i].S]=true;
    }
    int cnt=0;
    REP(i,n)
        if(successful[i])
            ++cnt;
    cout<<cnt<<endl;
    return 0;
}
