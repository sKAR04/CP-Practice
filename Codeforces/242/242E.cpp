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
ll arr[100010],lazy[1<<20];
ll segTree[1<<20][20];

void buildTree(ll low,ll high,ll pos){
    ll mid=(low+high)>>1;

    if(low==high){
        ll temp=arr[mid];
        DFOR(i,19,0){
            segTree[pos][i]=temp%2;
            temp/=2;
        }
    }
    else{
        buildTree(low,mid,2*pos+1);
        buildTree(mid+1,high,2*pos+2);

        DFOR(i,19,0)
            segTree[pos][i]=segTree[2*pos+1][i]+segTree[2*pos+2][i];
    }
}

void updateTree(ll low,ll high,ll pos,ll qLow,ll qHigh,ll x){
    ll mid=(low+high)>>1;
    if(lazy[pos]){
        ll len=high-low+1;
        ll temp=lazy[pos];
        DFOR(i,19,0){
            if(temp%2)
                segTree[pos][i]=len-segTree[pos][i];
            temp/=2;
        }

        if(low!=high){
            lazy[2*pos+1]^=lazy[pos];
            lazy[2*pos+2]^=lazy[pos];
        }

        lazy[pos]=0;
    }

    if(qLow>high || qHigh<low)
        return ;
    else if(qLow<=low && qHigh>=high){
        ll len=high-low+1;
        ll temp=x;
        DFOR(i,19,0){
            if(temp%2)
                segTree[pos][i]=len-segTree[pos][i];
            temp/=2;
        }

        if(low!=high){
            lazy[2*pos+1]^=x;
            lazy[2*pos+2]^=x;
        }
    }
    else{
        updateTree(low,mid,2*pos+1,qLow,qHigh,x);
        updateTree(mid+1,high,2*pos+2,qLow,qHigh,x);

        DFOR(i,19,0)
            segTree[pos][i]=segTree[2*pos+1][i]+segTree[2*pos+2][i];
    }
}

vll queryTree(ll low,ll high,ll pos,ll qLow,ll qHigh){
    ll mid=(low+high)>>1;

    if(lazy[pos]){
        ll len=high-low+1;
        ll temp=lazy[pos];
        DFOR(i,19,0){
            if(temp%2)
                segTree[pos][i]=len-segTree[pos][i];
            temp/=2;
        }

        if(low!=high){
            lazy[2*pos+1]^=lazy[pos];
            lazy[2*pos+2]^=lazy[pos];
        }

        lazy[pos]=0;
    }

    if(qLow<=low && qHigh>=high)
        return vll(segTree[pos],segTree[pos]+20);
    else if(qLow>high || qHigh<low)
        return vll(20,0);
    else{
        vll l=queryTree(low,mid,2*pos+1,qLow,qHigh);
        vll r=queryTree(mid+1,high,2*pos+2,qLow,qHigh);

        vll ans(20,0);
        REP(i,20)
            ans[i]=l[i]+r[i];

        return ans;
    }
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

    while(m--){
        int t;
        cin>>t;

        ll l,r;
        cin>>l>>r;

        --l;
        --r;

        if(t==1){
            vll cnt=queryTree(0,n-1,0,l,r);
            ll ans=0;
            REP(i,20)
                ans=ans+ll(cnt[i]<<(19-i));
            cout<<ans<<endl;
        }
        else{
            ll x;
            cin>>x;
            updateTree(0,n-1,0,l,r,x);
        }
    }

    return 0;
}
