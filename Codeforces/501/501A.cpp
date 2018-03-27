//Strike me down and I shall become stronger, than you can possibly imagine
//Streak Count : 4

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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int misha=max(3*a/10,a-(a/250)*c);
    int vasya=max(3*b/10,b-(b/250)*d);
    if(misha==vasya)
        cout<<"Tie"<<endl;
    else if(misha>vasya)
        cout<<"Misha"<<endl;
    else
        cout<<"Vasya"<<endl;
    return 0;
}
