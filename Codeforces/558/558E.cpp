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
class SegTree{
public:
    int arr[100010],tree[400010],lazy[400010];

    void build(int low,int high,int pos){
        int mid=(low+high)>>1;
        if(low==high)
            tree[pos]=arr[mid];
        else{
            build(low,mid,2*pos+1);
            build(mid+1,high,2*pos+2);
            tree[pos]=tree[2*pos+1]+tree[2*pos+2];
        }
    }

    void update(int low,int high,int pos,int qLow,int qHigh,int x){
        int mid=(low+high)>>1;

        if(low>high)
            return ;

        if(lazy[pos]!=-1){
            tree[pos]=(high-low+1)*lazy[pos];
            if(low!=high)
                lazy[2*pos+1]=lazy[2*pos+2]=lazy[pos];
            lazy[pos]=-1;
        }

        if(qLow>high || qHigh<low)
            return ;
        else if(qLow<=low && qHigh>=high){
            tree[pos]=(high-low+1)*x;
            if(low!=high)
                lazy[2*pos+1]=lazy[2*pos+2]=x;
        }
        else{
            update(low,mid,2*pos+1,qLow,qHigh,x);
            update(mid+1,high,2*pos+2,qLow,qHigh,x);
            tree[pos]=tree[2*pos+1]+tree[2*pos+2];
        }
    }

    int query(int low,int high,int pos,int qLow,int qHigh){
        int mid=(low+high)>>1;

        if(lazy[pos]!=-1){
            tree[pos]=(high-low+1)*lazy[pos];
            if(low!=high)
                lazy[2*pos+1]=lazy[2*pos+2]=lazy[pos];
            lazy[pos]=-1;
        }

        if(qLow>high || qHigh<low)
            return 0;
        else if(qLow<=low && qHigh>=high)
            return tree[pos];
        else
            return query(low,mid,2*pos+1,qLow,qHigh)+query(mid+1,high,2*pos+2,qLow,qHigh);
    }
};

SegTree t[26];
//Main function
int main(){
    IOS;
    TIE;

    int n,q;
    cin>>n>>q;

    string str;
    cin>>str;

    REP(i,n)
        ++(t[str[i]-97].arr[i]);
    REP(i,26){
        REP(j,400010)
            t[i].lazy[j]=-1;
        t[i].build(0,n-1,0);
    }

    while(q--){
        int l,r,x;
        cin>>l>>r>>x;

        --l;
        --r;

        if(x){
            int curL=l;
            REP(i,26){
                int sum=t[i].query(0,n-1,0,l,r);
                t[i].update(0,n-1,0,l,curL-1,0);
                t[i].update(0,n-1,0,curL,curL+sum-1,1);
                t[i].update(0,n-1,0,curL+sum,r,0);

                curL=curL+sum;
            }
        }
        else{
            int curL=l;
            DFOR(i,25,0){
                int sum=t[i].query(0,n-1,0,l,r);
                t[i].update(0,n-1,0,l,curL-1,0);
                t[i].update(0,n-1,0,curL,curL+sum-1,1);
                t[i].update(0,n-1,0,curL+sum,r,0);

                curL=curL+sum;
            }
        }
    }

    string ans="";
    REP(i,n)
        REP(j,26)
            if(t[j].query(0,n-1,0,i,i)){
                ans+=(char)(j+97);
                break;
            }
    cout<<ans<<endl;

    return 0;
}
