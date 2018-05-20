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
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
ll arr[100010];
ll segTree[1 << 18];

void buildTree(ll low,ll high,ll pos){
    ll mid=(low+high) >> 1;
    if(low==high)
        segTree[pos]=arr[mid];
    else{
        buildTree(low,mid,2*pos+1);
        buildTree(mid+1,high,2*pos+2);

        segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    }
}

ll queryTree(ll low,ll high,ll pos,ll qLow,ll qHigh){
    if(qHigh<low || qLow>high)
        return LLONG_MAX;
    else if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else{
        ll mid=(low+high) >> 1;
        return min(queryTree(low,mid,2*pos+1,qLow,qHigh),queryTree(mid+1,high,2*pos+2,qLow,qHigh));
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    FOR(j,1,t+1){
        cout<<"Scenario #"<<j<<":"<<endl;

        ll n,q;
        cin>>n>>q;

        REP(i,n)
            cin>>arr[i];
        buildTree(0,n-1,0);

        while(q--){
            ll a,b;
            cin>>a>>b;

            cout<<queryTree(0,n-1,0,a-1,b-1)<<endl;
        }
    }
    return 0;
}
