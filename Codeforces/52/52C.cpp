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
int segTree[1 << 20],lazyTree[1 << 20];
int arr[200010];

void buildTree(int low,int high,int pos){
    int mid=(low+high) >> 1;
    if(low==high)
        segTree[pos]=arr[mid];
    else{
        buildTree(low,mid,2*pos+1);
        buildTree(mid+1,high,2*pos+2);
        segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    }
}

void updateTree(int low,int high,int pos,int qLow,int qHigh,int val){
    int mid=(low+high) >> 1;
    if(lazyTree[pos]){
        segTree[pos]+=lazyTree[pos];
        if(low!=high){
            lazyTree[2*pos+1]+=lazyTree[pos];
            lazyTree[2*pos+2]+=lazyTree[pos];
        }
        lazyTree[pos]=0;
    }

    if(qLow>high || qHigh<low)
        return ;
    else if(qLow<=low && qHigh>=high){
        segTree[pos]+=val;
        if(low!=high){
            lazyTree[2*pos+1]+=val;
            lazyTree[2*pos+2]+=val;
        }
    }
    else{
        updateTree(low,mid,2*pos+1,qLow,qHigh,val);
        updateTree(mid+1,high,2*pos+2,qLow,qHigh,val);
        segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    }
}

int queryTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high) >> 1;
    if(lazyTree[pos]){
        segTree[pos]+=lazyTree[pos];
        if(low!=high){
            lazyTree[2*pos+1]+=lazyTree[pos];
            lazyTree[2*pos+2]+=lazyTree[pos];
        }
        lazyTree[pos]=0;
    }

    if(qLow>high || qHigh<low)
        return INF;
    else if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else
        return min(queryTree(low,mid,2*pos+1,qLow,qHigh),queryTree(mid+1,high,2*pos+2,qLow,qHigh));
}

string input;
int getNum(){
    int x=0;
    int idx=0;
    bool isNegative=false;
    if(input[idx]=='-'){
        isNegative=true;
        ++idx;
    }
    for(;input[idx]>47 && input[idx]<58 && idx<input.size();++idx)
        x=(x<<1)+(x<<3)+input[idx]-48;
    input.replace(0,idx+1,"");
    if(isNegative)
        x*=-1;
    return x;
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    REP(i,n)
        cin>>arr[i];
    buildTree(0,n-1,0);

    int m;
    cin>>m;
    getline(cin,input);

    REP(i,m){
        getline(cin,input);

        int l=getNum();
        int r=getNum();
        if(!input.size()){
            int minVal;
            if(l<=r)
                minVal=queryTree(0,n-1,0,l,r);
            else
                minVal=min(queryTree(0,n-1,0,0,r),queryTree(0,n-1,0,l,n-1));

            cout<<minVal<<endl;
        }
        else{
            int val=getNum();
            if(l<=r)
                updateTree(0,n-1,0,l,r,val);
            else{
                updateTree(0,n-1,0,l,n-1,val);
                updateTree(0,n-1,0,0,r,val);
            }
        }
    }

    return 0;
}
