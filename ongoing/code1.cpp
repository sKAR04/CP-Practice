/*
######################################################
#    I don't know what I'm doing with my life O.O    #
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
const int MAXN=300010;
int arr[MAXN],tmp[MAXN];
class SegTree{
public:
    int tree[4*MAXN],arr[MAXN];
    bool flag=false;
    void buildTree(int low,int high,int pos){
        int mid=(low+high)>>1;

        if(low==high)
            tree[pos]=arr[mid];
        else{
            buildTree(low,mid,2*pos+1);
            buildTree(mid+1,high,2*pos+2);
            if(!flag)
                tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
            else
                tree[pos]=min(tree[2*pos+1],tree[2*pos+2]);
        }
    }

    int query(int low,int high,int qLow,int qHigh,int pos){
        int mid=(low+high)>>1;

        if(qLow>high || qHigh<low){
            if(!flag)
                return INT_MIN;
            else
                return INT_MAX;
        }
        else if(low==high)
            return tree[pos];
        else{
            if(!flag)
                return max(query(low,mid,2*pos+1),query(mid+1,high,2*pos+2));
            else
                return min(query(low,mid,2*pos+1),query(mid+1,high,2*pos+2));
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    set<int> s;
    REP(i,n){
        cin>>arr[i];
        tmp[i]=arr[i];
        s.insert(arr[i]);
    }

    int cnt=0;
    map<int,int> idx;
    for(auto it=s.begin();it!=s.end();++it)
        idx[*it]=cnt++;

    FOR(i,1,n+1)
        arr[i]=idx[arr[i]];

    REP(i,n)
        if(!lPos[arr[i]])
            lPos[arr[i]]=i;

    DFOR(i,n-1,0)
        if(!rPos[arr[i]])
            rPos[arr[i]]=i;
    --cnt;

    SegTree lTree,rTree;
    REP(i,cnt){
        lTree.arr[i]=arr[i];
        rTree.arr[i]=arr[i];
    }
    lTree.flag=true;
    lTree.build(0,cnt,0);
    rTree.build(0,cnt,0);

    int k=INT_MAX,lVal,rVal;
    REP(i,n){
        lVal=max(0,)
    }


    return 0;
}
