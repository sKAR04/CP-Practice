
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
    vi posVect,negVect,zeroVect;
    REP(i,n){
        int temp;
        cin>>temp;
        if(temp>0)
            posVect.pb(temp);
        else if(temp)
            negVect.pb(temp);
        else
            zeroVect.pb(temp);
    }
    if(!posVect.size()){
        posVect.pb(negVect.back());
        negVect.pop_back();
        posVect.pb(negVect.back());
        negVect.pop_back();
    }
    if(negVect.size()%2==0){
        zeroVect.pb(negVect.back());
        negVect.pop_back();
    }
    cout<<negVect.size()<<" ";
    for(int x : negVect)
        cout<<x<<" ";
    cout<<endl<<posVect.size()<<" ";
    for(int x : posVect)
        cout<<x<<" ";
    cout<<endl<<zeroVect.size()<<" ";
    for(int x : zeroVect)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
