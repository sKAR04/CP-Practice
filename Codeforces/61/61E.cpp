/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

//Optimizations
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//save time
#define endl '\n'
#define db(x) cout << "> " << #x << ": " << x << endl;
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f

//loops
#define REP(i,n) 	    for(ll i=0;i<(n);++i)
#define FOR(i,a,b)      for(ll i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(ll i=(a);i>=(b);--i)

//vectors
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pair<int,int>>
#define vlll vector<pair<ll,ll>>
#define pb 	push_back

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//fast I/O
#ifndef _WIN32
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define gc getchar
#define pc putchar
#define scan getFoo

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
class SegTree{
public:
    int segTree[1<<22]={},arr[1000010]={};

    void buildTree(int low,int high,int pos){
        int mid=(low+high)>>1;
        if(low==high)
            segTree[pos]=arr[mid];
        else{
            buildTree(low,mid,2*pos+1);
            buildTree(mid+1,high,2*pos+2);
            segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
        }
    }

    void updateTree(int low,int high,int pos,int qPos,int val){
        int mid=(low+high)>>1;

        if(qPos<low || qPos>high)
            return ;
        else if(low==high)
            segTree[pos]=val;
        else{
            updateTree(low,mid,2*pos+1,qPos,val);
            updateTree(mid+1,high,2*pos+2,qPos,val);
            segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
        }
    }

    int queryTree(int low,int high,int pos,int qLow,int qHigh){
        int mid=(low+high)>>1;

        if(qLow<=low && qHigh>=high)
            return segTree[pos];
        else if(qLow>high || qHigh<low)
            return 0;
        else
            return queryTree(low,mid,2*pos+1,qLow,qHigh)+queryTree(mid+1,high,2*pos+2,qLow,qHigh);
    }
};

SegTree leftTree,rightTree;
int pos[1000010];
pi arr[1000010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    REP(i,n){
        cin>>arr[i].F;
        arr[i].S=i;
    }
    sort(arr,arr+n);

    REP(i,n){
        pos[arr[i].S]=i;
        rightTree.arr[i]=1;
    }
    rightTree.buildTree(0,n-1,0);

    ll ans=0;
    REP(i,n){
        ll l=0,r=0;

        if(pos[i]<n-1)
            l=leftTree.queryTree(0,n-1,0,pos[i]+1,n-1);
        if(pos[i])
            r=rightTree.queryTree(0,n-1,0,0,pos[i]-1);

        leftTree.updateTree(0,n-1,0,pos[i],1);
        rightTree.updateTree(0,n-1,0,pos[i],0);
        ans+=(l*r);
    }
    cout<<ans<<endl;

    return 0;
}
