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

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool flag=false;
    int n,x;
    cin>>n>>x;
    int cnt=0;
    vi v;
    REP(i,n){
        int temp;
        cin>>temp;
        if(temp==x)
            flag=true;
        v.pb(temp);
    }
    if(!flag){
        v.pb(x);
        ++cnt;
    }
    n=v.size();
    sort(all(v));
    int midVal=v[(n-1)/2];
    if(midVal>x){
        int idx=-1;
        REP(i,n)
            if(v[i]==x)
                idx=i;
        cnt+=(n-2*(idx+1));
    }
    else if(midVal<x){
        int idx=-1;
        REP(i,n)
            if(v[i]==x){
                idx=i;
                break;
            }
        cnt+=(2*idx+1-n);
    }
    cout<<cnt<<endl;
    return 0;
}
