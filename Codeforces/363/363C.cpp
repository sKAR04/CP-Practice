//Strike me down and I shall become stronger, than you can possibly imagine
//Streak Count : 5

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
    string str,ans="";
    cin>>str;
    while(str.size()){
        int len=str.size();
        if(len<3){
            ans+=str;
            str.replace(0,len,"");
        }
        else{
            if(str[0]==str[1] && str[1]==str[2]){
                int idx=0;
                while(idx<len)
                    if(str[idx]==str[0])
                        ++idx;
                    else{
                        --idx;
                        break;
                    }
                if(idx==len)
                    --idx;
                str.replace(0,idx-1,"");
            }
            else if(str[0]==str[1]){
                if(len>3){
                    if(str[2]==str[3]){
                        int idx=2;
                        while(idx<len)
                            if(str[idx]==str[2])
                                ++idx;
                            else{
                                --idx;
                                break;
                            }
                        if(idx==len)
                            --idx;
                        ans+=str.substr(0,3);
                        str.replace(0,idx+1,"");
                    }
                    else{
                        ans+=str.substr(0,3);
                        str.replace(0,3,"");
                    }
                }
                else{
                    ans+=str;
                    str.replace(0,len,"");
                }
            }
            else if(str[1]==str[2]){
                ans+=str[0];
                str.replace(0,1,"");
            }
            else{
                ans+=str.substr(0,2);
                str.replace(0,2,"");
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
