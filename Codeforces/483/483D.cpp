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
struct Query{
    int l,r,q;
};

Query queries[100010];
int sum[100010][30];
int arr[100010];

int segTree[1<<19];
void buildTree(int low,int high,int pos){
    int mid=(low+high)>>1;

    if(low==high)
        segTree[pos]=arr[mid];
    else{
        buildTree(low,mid,2*pos);
        buildTree(mid+1,high,2*pos+1);
        segTree[pos]=segTree[2*pos]&segTree[2*pos+1];
    }
}

int queryTree(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high)>>1;

    if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else if(qLow>high || qHigh<low)
        return (1<<30)-1;
    else
        return queryTree(low,mid,2*pos,qLow,qHigh)&queryTree(mid+1,high,2*pos+1,qLow,qHigh);
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    REP(i,m){
        cin>>queries[i].l>>queries[i].r>>queries[i].q;
        int cur=queries[i].q;
        DFOR(j,29,0){
            sum[queries[i].l][j]+=cur&1;
            sum[queries[i].r+1][j]-=(cur&1);
            cur>>=1;
        }
    }

    int curSum[30]={};
    FOR(i,1,n+1){
        REP(j,30){
            curSum[j]+=sum[i][j];
            arr[i]<<=1;
            arr[i]+=(curSum[j]>0);
        }
    }
    buildTree(1,n,1);

    bool flag=true;
    REP(i,m)
        if(queryTree(1,n,1,queries[i].l,queries[i].r)!=queries[i].q){
            flag=false;
            break;
        }

    if(flag){
        cout<<"YES"<<endl;
        FOR(i,1,n+1)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
