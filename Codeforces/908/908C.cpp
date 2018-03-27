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
double r;
int isOccupied[1010];
double height[1010];
double x[1010];

double getMaxHeight(int add,int base){
    double xEff=x[base]-x[add];
    double maxHeight=sqrt(4.0*r*r-(xEff*xEff));
    return maxHeight+height[base];
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n>>r;
    FOR(i,1,n+1)
        cin>>x[i];
    FOR(i,1,n+1){
        double maxHeight=r;
        FOR(j,max(1.0,x[i]-r),min(1000.0,x[i]+r)+1)
            if(isOccupied[j])
                maxHeight=max(maxHeight,getMaxHeight(i,isOccupied[j]));
        height[i]=maxHeight;
        FOR(j,max(1.0,x[i]-r),min(1000.0,x[i]+r)+1)
            isOccupied[j]=i;
    }
    FOR(i,1,n+1)
        cout<<setprecision(15)<<height[i]<<" ";
    cout<<endl;
    return 0;
}
