
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
    int cnt=0;
    string str;
    cin>>str;
    int len=str.length();
    REP(i,len){
        if(str[i]=='h' && cnt==0)
            ++cnt;
        if(str[i]=='e' && cnt==1)
            ++cnt;
        if(str[i]=='l' && (cnt==2 || cnt==3))
            ++cnt;
        if(str[i]=='o' && cnt==4)
            ++cnt;
    }
    if(cnt==5)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
