
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
    int arr[10];
    int n;
    cin>>n;
    FOR(i,1,10)
        cin>>arr[i];
    string ans="";
    int minPaint=INT_MAX,maxNum=-1;
    FOR(i,1,10)
        if(minPaint>=arr[i]){
            minPaint=arr[i];
            maxNum=i;
        }
    REP(i,n/minPaint)
        ans+=(char)(48+maxNum);
    n%=minPaint;
    int idx=0,len=ans.size();
    DFOR(i,9,maxNum+1){
        while(n-arr[i]+minPaint>=0 && idx<len){
            ans[idx++]=(char)(48+i);
            n-=(arr[i]-minPaint);
        }
    }
    if(len)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
