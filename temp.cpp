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
#define MOD  1000000009LL
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
ll fib[300010];
void genFib(){
    fib[0]=fib[1]=1LL;
    FOR(i,2,300010)
        fib[i]=(fib[i-1]+fib[i-2])%MOD;

    FOR(i,1,300010)
        fib[i]=(fib[i-1]+fib[i])%MOD;
}

ll segTree[1 << 21],lazyTree[1 << 21];
ll arr[300010];
void buildTree(int low,int high,int pos){
    int mid=(low+high) >> 1;
    if(low==high)
        segTree[pos]=arr[mid];
    else{
        buildTree(low,mid,2*pos+1);
        buildTree(mid+1,high,2*pos+2);
        segTree[pos]=(segTree[2*pos+1]+segTree[2*pos+2])%MOD;
    }
}

void updateTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high) >> 1;
    if(lazyTree[pos]){
        segTree[pos]=(lazyTree[pos]+segTree[pos])%MOD;
        if(low!=high){
            lazyTree[2*pos+1]=(lazyTree[2*pos+1]+fib[mid-low])%MOD;
            lazyTree[2*pos+2]=(lazyTree[2*pos+2]+fib[high-low]-fib[mid-low]+MOD)%MOD;
        }
        lazyTree[pos]=0LL;
    }

    if(qLow>high || qHigh<low)
        return ;
    else if(qLow<=low && qHigh>=high){
        segTree[pos]=(segTree[pos]+fib[(high-low)])%MOD;
        if(low!=high){
            lazyTree[2*pos+1]=(lazyTree[2*pos+1]+fib[(mid-low)])%MOD;
            lazyTree[2*pos+2]=(lazyTree[2*pos+2]+fib[(high-low)]-fib[(mid-low)]+MOD)%MOD;
        }
    }
    else{
        updateTree(low,mid,2*pos+1,qLow,qHigh);
        updateTree(mid+1,high,2*pos+2,qLow,qHigh);
        segTree[pos]=(segTree[2*pos+1]+segTree[2*pos+2])%MOD;
    }
}

ll queryTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high) >> 1;
    if(lazyTree[pos]){
        segTree[pos]=(lazyTree[pos]+segTree[pos])%MOD;
        if(low!=high){
            lazyTree[2*pos+1]=(lazyTree[2*pos+1]+fib[(mid-low)])%MOD;
            lazyTree[2*pos+2]=(lazyTree[2*pos+2]+fib[(high-low)]-fib[(mid-low)]+MOD)%MOD;
        }
        lazyTree[pos]=0LL;
    }

    if(qLow>high || qHigh<low)
        return 0LL;
    else if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else
        return (queryTree(low,mid,2*pos+1,qLow,qHigh)+queryTree(mid+1,high,2*pos+2,qLow,qHigh))%MOD;
}
//Main function
int main(){
    IOS;
    TIE;

    genFib();

    int n,m;
    cin>>n>>m;

    REP(i,n)
        cin>>arr[i];
    buildTree(0,n-1,0);

    REP(i,m){
        int q,l,r;
        cin>>q>>l>>r;

        --l;
        --r;

        if(q==1)
            updateTree(0,n-1,0,l,r);
        else
            cout<<queryTree(0,n-1,0,l,r)<<endl;
    }

    return 0;
}
