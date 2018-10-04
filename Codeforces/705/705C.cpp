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
int tree[1200010],lazy[1200010];
vi unread[300010];
void update(int low,int high,int pos,int qLow,int qHigh,int val){
    int mid=(low+high)>>1;

    if(lazy[pos]!=-1){
        tree[pos]=0;
        if(low!=high)
            lazy[2*pos+1]=lazy[2*pos+2]=0;
        lazy[pos]=-1;
    }

    if(qLow>high || qHigh<low)
        return ;
    else if(qLow<=low && qHigh>=high){
        if(low==high)
            tree[pos]=val;
        else
            tree[pos]=0;

        if(low!=high)
            lazy[2*pos+1]=lazy[2*pos+2]=0;
    }
    else{
        update(low,mid,2*pos+1,qLow,qHigh,val);
        update(mid+1,high,2*pos+2,qLow,qHigh,val);
        tree[pos]=tree[2*pos+1]+tree[2*pos+2];
    }
}

int query(int low,int high,int pos,int qLow,int qHigh){
    int mid=(low+high)>>1;

    if(lazy[pos]!=-1){
        tree[pos]=0;
        if(low!=high)
            lazy[2*pos+1]=lazy[2*pos+2]=0;
        lazy[pos]=-1;
    }

    if(qLow>high || qHigh<low)
        return 0;
    else if(qLow<=low && qHigh>=high)
        return tree[pos];
    else
        return query(low,mid,2*pos+1,qLow,qHigh)+query(mid+1,high,2*pos+2,qLow,qHigh);
}
//Main function
int main(){
    IOS;
    TIE;

    int n,q;
    cin>>n>>q;

    fill(lazy,lazy+1200010,-1);

    int cnt=0;
    REP(i,q){
        int type,x;
        cin>>type>>x;

        if(type==1){
            update(0,q-1,0,cnt,cnt,1);
            unread[x].pb(cnt);
            ++cnt;
        }
        else if(type==2){
            for(int notif : unread[x])
                update(0,q-1,0,notif,notif,0);
            unread[x].clear();
        }
        else
            update(0,q-1,0,0,x-1,0);
        cout<<query(0,q-1,0,0,cnt)<<endl;
    }
    return 0;
}
