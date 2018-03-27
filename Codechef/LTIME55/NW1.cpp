
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
    int t;
    cin>>t;
    map<string,int> dayMap;
    dayMap["mon"]=0;
    dayMap["tues"]=1;
    dayMap["wed"]=2;
    dayMap["thurs"]=3;
    dayMap["fri"]=4;
    dayMap["sat"]=5;
    dayMap["sun"]=6;
    while(t--){
        int d;
        string str;
        cin>>d>>str;
        int val[7]={0};
        int curIdx=dayMap[str];
        while(d){
            ++val[curIdx];
            curIdx=(curIdx+1)%7;
            --d;
        }
        REP(i,7)
            cout<<val[i]<<" ";
        cout<<endl;
    }
    return 0;
}
