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
#define vii vector<pair<int,int> >
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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int n;
ll arr[100010];
vll vol;
int idx[100010];

ll segTree[1 << 18];

ll queryTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high) >> 1;

    if(low>qHigh || high<qLow)
        return 0LL;
    else if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else
        return max(queryTree(low,mid,2*pos+1,qLow,qHigh),queryTree(mid+1,high,2*pos+2,qLow,qHigh));
}

void updateTree(int low,int high,int pos,int qPos,ll val){
    int mid=(low+high) >> 1;

    if(low>qPos || high<qPos)
        return ;
    else if(low==high)
        segTree[pos]=max(segTree[pos],val);
    else{
        updateTree(low,mid,2*pos+1,qPos,val);
        updateTree(mid+1,high,2*pos+2,qPos,val);
        segTree[pos]=max(segTree[2*pos+1],segTree[2*pos+2]);
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    REP(i,n){
        ll r,h;
        cin>>r>>h;
        arr[i]=r*r*h;
        vol.pb(arr[i]);
    }
    sort(all(vol));
    REP(i,n)
        idx[i]=lower_bound(all(vol),arr[i])-vol.begin();

    REP(i,n){
        ll maxVal;
        if(idx[i])
            maxVal=queryTree(0,n-1,0,0,idx[i]-1);
        else
            maxVal=0;
        updateTree(0,n-1,0,idx[i],maxVal+arr[i]);
    }
    cout<<setprecision(20)<<PI*(double)segTree[0]<<endl;

    return 0;
}
