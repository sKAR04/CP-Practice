
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
    string str;
    cin>>str;
    int len=str.length();
    if(len<7)
        cout<<"NO"<<endl;
    else{
        int sum=0;
        queue<int> q;
        REP(i,7){
            q.push(str[i]-48);
            sum+=(str[i]-48);
        }
        bool flag=true;
        FOR(i,7,len){
            if(sum==0 || sum==7){
                flag=false;
                break;
            }
            sum-=(q.front());
            q.pop();
            q.push(str[i]-48);
            sum+=(str[i]-48);
        }
        if(sum==0 || sum==7)
            flag=false;
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
