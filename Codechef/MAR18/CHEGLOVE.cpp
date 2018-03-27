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
    int n;
    cin>>n;

    int fingers[n];
    REP(i,n)
        cin>>fingers[i];

    int gloves[n];
    REP(i,n)
        cin>>gloves[i];

    int cnt=0;
    bool flag=true;

    REP(i,n)
        if(fingers[i]>gloves[i]){
            flag=false;
            break;
        }

    if(flag)
        cnt+=1;

    flag=true;
    REP(i,n)
        if(fingers[i]>gloves[n-1-i]){
            flag=false;
            break;
        }

    if(flag)
        cnt+=2;

    switch(cnt){
        case 0 : cout<<"none"<<'\n'; break;
        case 1 : cout<<"front"<<'\n'; break;
        case 2 : cout<<"back"<<'\n'; break;
        case 3 : cout<<"both"<<'\n'; break;
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
