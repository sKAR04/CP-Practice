//Strike me down and I shall become stronger, than you can possibly imagine
//Streak Count : 2

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
int segTree[1 << 20];
int arr[1 << 18];
void buildTree(int low,int high,int pos,int level){
    int mid=(low+high) >> 1;
    if(low==high)
        segTree[pos]=arr[mid];
    else{
        buildTree(low,mid,2*pos+1,level-1);
        buildTree(mid+1,high,2*pos+2,level-1);
        if(level & 1)
            segTree[pos]=(segTree[2*pos+1] | segTree[2*pos+2]);
        else
            segTree[pos]=(segTree[2*pos+1] ^ segTree[2*pos+2]);
    }
}

void updateTree(int low,int high,int pos,int idx,int level){
    int mid=(low+high) >> 1;
    if(idx<low || idx>high)
        return ;
    else if(low==high)
        segTree[pos]=arr[mid];
    else{
        updateTree(low,mid,2*pos+1,idx,level-1);
        updateTree(mid+1,high,2*pos+2,idx,level-1);
        if(level & 1)
            segTree[pos]=(segTree[2*pos+1] | segTree[2*pos+2]);
        else
            segTree[pos]=(segTree[2*pos+1] ^ segTree[2*pos+2]);
    }
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,level;
    cin>>n>>m;
    level=n;
    n = (1 << n);
    REP(i,n)
        cin>>arr[i];
    buildTree(0,n-1,0,level);
    while(m--){
        int idx,val;
        cin>>idx>>val;
        --idx;
        arr[idx]=val;
        updateTree(0,n-1,0,idx,level);
        cout<<segTree[0]<<endl;
    }
    return 0;
}
