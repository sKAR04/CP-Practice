
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
    int n;
    cin>>n;
    int up=0,down=0,type1=0,type2=0;
    REP(i,n){
        int u,d;
        cin>>u>>d;
        up+=u;
        down+=d;
        if(u%2==0 && d%2)
            ++type1;
        else if(u%2 && d%2==0)
            ++type2;
    }
    if(up%2==0 && down%2==0)
        cout<<0<<endl;
    else if(up%2==1 && down%2==1 && (type1 || type2))
        cout<<1<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
