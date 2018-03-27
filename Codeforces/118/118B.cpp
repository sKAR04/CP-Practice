
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
string genStr(int n){
    string ans="";
    REP(i,n){
        ans+=(char)(i+48);
        ans+=" ";
    }
    ans+=(char)(n+48);
    ans+=" ";
    DFOR(i,n-1,0){
        ans+=(char)(i+48);
        ans+=" ";
    }
    ans.replace(ans.length()-1,1,"");
    return ans;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string temp[n+1];
    REP(i,n+1)
        temp[i]=genStr(i);
    REP(i,n){
        REP(j,n-i)
            cout<<"  ";
        cout<<temp[i]<<endl;
    }
    cout<<temp[n]<<endl;
    DFOR(i,n-1,0){
        REP(j,n-i)
            cout<<"  ";
        cout<<temp[i]<<endl;
    }
    return 0;
}
