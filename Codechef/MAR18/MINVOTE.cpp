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
ll leftSum[100010];
ll rightSum[100010];
ll arr[100010];

int n;

int binarySearchLeft(int low,int high,int pos,ll offset){
    int mid=(low+high) >> 1;

    if(low>high)
        return mid;
    else{
        if(arr[pos]==leftSum[mid]-offset)
            return mid;
        else if(arr[pos]>leftSum[mid]-offset)
            return binarySearchLeft(mid+1,high,pos,offset);
        else
            return binarySearchLeft(low,mid-1,pos,offset);
    }
}

int binarySearchRight(int low,int high,int pos,ll offset){
    int mid=(low+high) >> 1;

    if(low>high)
        return mid;
    else{
        if(arr[pos]==rightSum[mid]-offset)
            return mid;
        else if(arr[pos]<rightSum[mid]-offset)
            return binarySearchRight(mid+1,high,pos,offset);
        else
            return binarySearchRight(low,mid-1,pos,offset);
    }
}

inline void solve(){
    cin>>n;
    FOR(i,1,n+1)
        cin>>arr[i];

    FOR(i,1,n+1)
        leftSum[i]=leftSum[i-1]+arr[i];
    DFOR(i,n,1)
        rightSum[i]=rightSum[i+1]+arr[i];

    ll ansLeft[100010]={0LL};
    ll ansRight[100010]={0LL};

    FOR(i,1,n+1){
        int idx=binarySearchLeft(i+1,n,i,leftSum[i]);
        if(arr[i]>=leftSum[idx]-leftSum[i])
            --ansLeft[idx+2];
        else
            --ansLeft[idx+1];
        ++ansLeft[i+1];
    }

    DFOR(i,n,1){
        int idx=binarySearchRight(1,i-1,i,rightSum[i]);
        if(arr[i]>=rightSum[idx]-rightSum[i] && idx>1)
            --ansRight[idx-2];
        else
            --ansRight[idx-1];
        ++ansRight[i-1];
    }

    ll curSum=0LL;
    FOR(i,1,n+1){
        curSum+=ansLeft[i];
        ansLeft[i]=curSum;
    }

    curSum=0LL;
    DFOR(i,n,1){
        curSum+=ansRight[i];
        ansRight[i]=curSum;
    }

    FOR(i,1,n+1)
        cout<<ansLeft[i]+ansRight[i]<<" ";

    cout<<endl;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
