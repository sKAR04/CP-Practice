
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
int toNum(string str){
    int num=0,len=str.length();
    REP(i,len)
        num=(num << 1)+(num << 3)+(str[i]-48);
    return num;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>str;
    int len=str.length();
    REP(i,len){
        int val=toNum(str.substr(i,1));
        if(val%8==0){
            cout<<"YES"<<endl<<val<<endl;
            return 0;
        }
    }
    REP(i,len)
        FOR(j,i+1,len){
            string temp="";
            temp+=str[i];
            temp+=str[j];
            int val=toNum(temp);
            if(val%8==0){
                cout<<"YES"<<endl<<val<<endl;
                return 0;
            }
        }
    REP(i,len)
        FOR(j,i+1,len)
            FOR(k,j+1,len){
                string temp="";
                temp+=str[i];
                temp+=str[j];
                temp+=str[k];
                int val=toNum(temp);
                if(val%8==0){
                    cout<<"YES"<<endl<<val<<endl;
                    return 0;
                }
            }
    cout<<"NO"<<endl;
    return 0;
}
