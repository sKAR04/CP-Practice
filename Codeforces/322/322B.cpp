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
int a,b,c;
int tempA,tempB,tempC;

void fuckMyLife(int delta){
    tempA=a-delta;
    tempB=b-delta;
    tempC=c-delta;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b>>c;
    int ans=0;
    fuckMyLife(0);
    ans=max(ans,tempA/3+tempB/3+tempC/3);
    fuckMyLife(1);
    if(a && b && c)
        ans=max(ans,tempA/3+tempB/3+tempC/3+1);
    fuckMyLife(2);
    if(a>2 && b>2 && c>2)
        ans=max(ans,tempA/3+tempB/3+tempC/3+2);
    cout<<ans<<endl;
    return 0;
}
