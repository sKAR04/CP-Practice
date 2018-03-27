
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
int binarySearch(vll arr,int low,int high,ll key){
    int mid=(low+high) >> 1;
    if(low<=high){
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            return binarySearch(arr,low,mid-1,key);
        else
            return binarySearch(arr,mid+1,high,key);
    }
    else
        return mid;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll arr[n];
        REP(i,n)
            REP(j,n){
                ll temp;
                cin>>temp;
                arr[i].pb(temp);
            }
        REP(i,n)
            sort(all(arr[i]));
        bool flag=true;
        ll ans=0,prevMax=LLONG_MAX;
        DFOR(i,n-1,0){
            int idx=binarySearch(arr[i],0,n-1,prevMax-1);
            if(arr[i][idx]<=prevMax-1){
                ans+=arr[i][idx];
                prevMax=arr[i][idx];
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
