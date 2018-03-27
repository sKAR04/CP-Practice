
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
ll board[2010][2010];
ll diag1[4020],diag2[4020];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    FOR(i,1,n+1)
        FOR(j,1,n+1){
            cin>>board[i][j];
            diag1[i+j]+=board[i][j];
            diag2[i-j+n]+=board[i][j];
        }
    ll max1=LLONG_MIN,max2=LLONG_MIN;
    int x1,y1,x2,y2;
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            int ref=(i+j);
            ll curVal=diag1[i+j]+diag2[i-j+n]-board[i][j];
            if(ref & 1){
                if(curVal>max1){
                    x1=i;
                    y1=j;
                    max1=curVal;
                }
            }
            else{
                if(curVal>max2){
                    x2=i;
                    y2=j;
                    max2=curVal;
                }
            }
        }
    }
    cout<<max1+max2<<endl;
    cout<<x2<<" "<<y2<<" "<<x1<<" "<<y1<<endl;
    return 0;
}
