/*
######################################################
# Let's see where this is going to lead me shall we? #
######################################################
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
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
const int MAXN=100010;
ll tree[4*MAXN],lazy[4*MAXN],arr[MAXN],k[MAXN],maxVal[4*MAXN];

void update(int low,int high,int pos,int qLow,int qHigh,ll val){
    int mid=(low+high)>>1;
    if(lazy[pos]!=LLONG_MIN){
        tree[pos]=lazy[pos]*(high-low+1);
        maxVal[pos]=lazy[pos];
        if(low!=high){
            lazy[2*pos]=lazy[pos];
            lazy[2*pos+1]=lazy[pos];
        }
        lazy[pos]=LLONG_MIN;
    }

    if(qLow>high || qHigh<low)
        return ;
    else if(qLow<=low && qHigh>=high){
        tree[pos]=val*(high-low+1);
        maxVal[pos]=val;
        if(low!=high){
            lazy[2*pos]=val;
            lazy[2*pos+1]=val;
        }
    }
    else{
        update(low,mid,2*pos,qLow,qHigh,val);
        update(mid+1,high,2*pos+1,qLow,qHigh,val);
        tree[pos]=tree[2*pos]+tree[2*pos+1];
        maxVal[pos]=max(maxVal[2*pos],maxVal[2*pos+1]);
    }
}

ll querySum(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high)>>1;
    if(lazy[pos]!=LLONG_MIN){
        tree[pos]=lazy[pos]*(high-low+1);
        maxVal[pos]=lazy[pos];
        if(low!=high){
            lazy[2*pos]=lazy[pos];
            lazy[2*pos+1]=lazy[pos];
        }
        lazy[pos]=LLONG_MIN;
    }

    if(qLow>high || qHigh<low)
        return 0LL;
    else if(qLow<=low && qHigh>=high)
        return tree[pos];
    else
        return querySum(low,mid,2*pos,qLow,qHigh)+querySum(mid+1,high,2*pos+1,qLow,qHigh);
}

int queryMaxPos(int low,int high,int pos,int qLow,int qHigh,ll val){
    int mid=(low+high)>>1;
    if(lazy[pos]!=LLONG_MIN){
        tree[pos]=lazy[pos]*(high-low+1);
        maxVal[pos]=lazy[pos];
        if(low!=high){
            lazy[2*pos]=lazy[pos];
            lazy[2*pos+1]=lazy[pos];
        }
        lazy[pos]=LLONG_MIN;
    }

    if(low==high)
        return (maxVal[pos]<=val?mid:-1);
    else if(maxVal[pos]<=val)
        return high;
    else{
        ll leftMax=maxVal[2*pos],rightMax=maxVal[2*pos+1];
        if(lazy[2*pos]!=LLONG_MIN)
            leftMax=lazy[2*pos];
        if(lazy[2*pos+1]!=LLONG_MIN)
            rightMax=lazy[2*pos+1];

        if(leftMax<=val)
            return max(mid,queryMaxPos(mid+1,high,2*pos+1,qLow,qHigh,val));
        else
            return queryMaxPos(low,mid,2*pos,qLow,qHigh,val);
    }
}

void buildTree(int low,int high,int pos){
    int mid=(low+high)>>1;
    lazy[pos]=LLONG_MIN;

    if(low==high){
        tree[pos]=arr[mid];
        maxVal[pos]=arr[mid];
    }
    else{
        buildTree(low,mid,2*pos);
        buildTree(mid+1,high,2*pos+1);
        tree[pos]=tree[2*pos]+tree[2*pos+1];
        maxVal[pos]=max(maxVal[2*pos],maxVal[2*pos+1]);
    }
}

//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    FOR(i,1,n+1)
        cin>>arr[i];

    FOR(i,2,n+1){
        cin>>k[i];
        k[i]+=k[i-1];
    }

    FOR(i,1,n+1)
        arr[i]-=k[i];
    buildTree(1,n,1);

    FOR(i,1,n+1)
        k[i]+=k[i-1];

    int q;
    cin>>q;

    char c;
    int l,r;
    while(q--){
        cin>>c>>l>>r;

        if(c=='s')
            cout<<querySum(1,n,1,l,r)+k[r]-k[l-1]<<endl;
        else{
            int minIdx=queryMaxPos(1,n,1,l,n,r+querySum(1,n,1,l,l));
            //db(minIdx);
            //db(r+querySum(1,n,1,l,l));
            update(1,n,1,l,minIdx,r+querySum(1,n,1,l,l));
        }

        // FOR(i,1,n+1)
        //     cout<<querySum(1,n,1,i,i)+k[i]-k[i-1]<<" ";
        // cout<<"\n###################"<<endl;
    }

    return 0;
}
