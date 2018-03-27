
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
    while(t--){
        ll n,x;
        cin>>x>>n;
        if(n<4)
            cout<<"impossible"<<endl;
        else{
            ll sum=n*(n+1)/2-x;
            if(sum & 1LL)
                cout<<"impossible"<<endl;
            else{
                sum/=2;
                int str[n];
                fill(str,str+n,0);
                str[x-1]=2;
                DFOR(i,n-1,0){
                    if(!sum)
                        break;
                    if(i!=x-1){
                        if(sum>=i+1){
                            str[i]=1;
                            sum-=(i+1);
                        }
                        else if(!str[sum-1]){
                            str[sum-1]=1;
                            sum=0;
                        }
                    }
                }
                if(!sum){
                    REP(i,n)
                        cout<<str[i];
                    cout<<endl;
                }
                else{
                    sum=n*(n+1)/2-x;
                    sum/=2;
                    sum-=n;
                    fill(str,str+n,0);
                    str[n-1]=1;
                    str[x-1]=2;
                    DFOR(i,n-3,0){
                        if(!sum)
                            break;
                        if(i!=x-1){
                            if(sum>=i+1){
                                str[i]=1;
                                sum-=(i+1);
                            }
                            else if(!str[sum-1]){
                                str[sum-1]=1;
                                sum=0;
                            }
                        }
                    }
                    REP(i,n)
                        cout<<str[i];
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
