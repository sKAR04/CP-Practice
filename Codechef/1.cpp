//Strike me down and I shall become stronger, than you can possibly imagine

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <cmath>

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
ll arr[200010];
struct MergeSortTreeNode{
    vll nodeVect;
    ll maxPer=0LL;
};

MergeSortTreeNode mergeSortTree[1 << 18];

MergeSortTreeNode merge(MergeSortTreeNode n1,MergeSortTreeNode n2){
    MergeSortTreeNode newNode;
    vector<pair<ll,int> > tempVect;

    int n=n1.nodeVect.size();
    int m=n2.nodeVect.size();

    int i=0,j=0;

    while(i<n && j<m){
        if(n1.nodeVect[i]<=n2.nodeVect[j]){
            newNode.nodeVect.pb(n1.nodeVect[i]);
            tempVect.pb(mp(n1.nodeVect[i++],1));
        }
        else{
            newNode.nodeVect.pb(n2.nodeVect[j]);
            tempVect.pb(mp(n2.nodeVect[j++],2));
        }
    }

    while(i<n){
        newNode.nodeVect.pb(n1.nodeVect[i]);
        tempVect.pb(mp(n1.nodeVect[i++],1));
    }

    while(j<m){
        newNode.nodeVect.pb(n2.nodeVect[j]);
        tempVect.pb(mp(n2.nodeVect[j++],2));
    }

    int N=n+m;

    DFOR(i,N-1,2)
        if(tempVect[i].F<tempVect[i-1].F+tempVect[i-2].F && (tempVect[i].S+tempVect[i-1].S+tempVect[i-2].S)%3){
            newNode.maxPer=tempVect[i].F+tempVect[i-1].F+tempVect[i-2].F;
            break;
        }

    newNode.maxPer=max(newNode.maxPer,max(n1.maxPer,n2.maxPer));

    return newNode;
}

void buildTree(int low,int high,int pos){
    int mid=(low+high) >> 1;

    if(low==high)
        mergeSortTree[pos].nodeVect.pb(arr[mid]);
    else{
        buildTree(low,mid,2*pos+1);
        buildTree(mid+1,high,2*pos+2);

        mergeSortTree[pos]=merge(mergeSortTree[2*pos+1],mergeSortTree[2*pos+2]);
    }
}

MergeSortTreeNode queryTree(int low,int high,int qLow,int qHigh,int pos){
    int mid=(low+high) >> 1;

    MergeSortTreeNode ans;

    if(low>qHigh || high<qLow)
        return ans;
    else if(qLow<=low && qHigh>=high)
        return mergeSortTree[pos];
    else
        return merge(queryTree(low,mid,qLow,qHigh,2*pos+1),queryTree(mid+1,high,qLow,qHigh,2*pos+2));
}

void updateTree(int low,int high,int pos,int qPos){
    int mid=(low+high) >> 1;

    MergeSortTreeNode newNode;

    if(low==high){
        newNode.nodeVect.pb(arr[mid]);
        mergeSortTree[pos]=newNode;
    }
    else if(low>qPos || high<qPos)
        return ;
    else{
        updateTree(low,mid,2*pos+1,qPos);
        updateTree(mid+1,high,2*pos+2,qPos);

        mergeSortTree[pos]=merge(mergeSortTree[2*pos+1],mergeSortTree[2*pos+2]);
    }
}

inline void solve(){
    int n,q;
    cin>>n>>q;

    REP(i,n)
        cin>>arr[i];

    buildTree(0,n-1,0);

    while(q--){
        int qType,l,r;
        cin>>qType>>l>>r;

        if(qType==1){
            --l;
            arr[l]=r;
            updateTree(0,n-1,0,l);
        }
        else if(qType==2){
            --l;
            --r;
            cout<<(queryTree(0,n-1,l,r,0)).maxPer<<endl;
        }
    }
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
