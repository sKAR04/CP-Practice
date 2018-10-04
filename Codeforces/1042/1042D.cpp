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
const int MAXN=200010;
ll arr[MAXN];
int tree[4*MAXN];

void update(int low,int high,int pos,int qPos){
    int mid=(low+high)>>1;

    if(low>qPos || high<qPos)
        return ;
    else if(low==high)
        ++tree[pos];
    else{
        update(low,mid,2*pos+1,qPos);
        update(mid+1,high,2*pos+2,qPos);
        tree[pos]=tree[2*pos+1]+tree[2*pos+2];
    }
}

int query(int low,int high,int pos,int l,int r){
    int mid=(low+high)>>1;
    if(high<l || low>r)
        return 0;
    else if(l<=low && r>=high)
        return tree[pos];
    else
        return query(low,mid,2*pos+1,l,r)+query(mid+1,high,2*pos+2,l,r);
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    ll t;
    cin>>n>>t;

    vll sum(n+1,0LL);
    ll curSum=0;
    FOR(i,1,n+1){
        cin>>arr[i];
        curSum+=arr[i];
        sum[i]=curSum;
    }
    sort(all(sum));

    ll ans=0;
    curSum=0;
    REP(i,n+1){
        curSum+=arr[i];
        ans+=query(0,n,0,upper_bound(all(sum),curSum-t)-sum.begin(),n);
        int idx=lower_bound(all(sum),curSum)-sum.begin();
        update(0,n,0,idx);
    }
    cout<<ans<<endl;

    return 0;
}
