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
    int len;
    string str;
    int tree[1<<22][3];

    void build(){
        build(0,len-1,0);
    }

    void build(int low,int high,int pos){
        int mid=(low+high)>>1;
        if(low==high){
            if(str[mid]=='(')
                tree[pos][0]=1;
            else
                tree[pos][1]=1;
        }
        else{
            build(low,mid,2*pos+1);
            build(mid+1,high,2*pos+2);

            int cross=min(tree[2*pos+1][0],tree[2*pos+2][1]);
            tree[pos][2]=tree[2*pos+1][2]+tree[2*pos+2][2]+cross;
            tree[pos][1]=tree[2*pos+1][1]+tree[2*pos+2][1]-cross;
            tree[pos][0]=tree[2*pos+1][0]+tree[2*pos+2][0]-cross;
        }
    }

    vi query(int qLow,int qHigh){
        return query(0,len-1,0,qLow,qHigh);
    }

    vi query(int low,int high,int pos,int qLow,int qHigh){
        int mid=(low+high)>>1;

        if(qLow>high || qHigh<low)
            return vi(3,0);
        else if(qLow<=low && qHigh>=high)
            return vi{tree[pos][0],tree[pos][1],tree[pos][2]};
        else{
            vi l=query(low,mid,2*pos+1,qLow,qHigh),r=query(mid+1,high,2*pos+2,qLow,qHigh);
            int cross=min(l[0],r[1]);
            l[2]=l[2]+r[2]+cross;
            l[1]=l[1]+r[1]-cross;
            l[0]=l[0]+r[0]-cross;

            return l;
        }
    }
};


SegTree t;
//Main function
int main(){
    IOS;
    TIE;

    cin>>t.str;
    t.len=t.str.length();
    t.build();

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<2*(t.query(l-1,r-1))[2]<<endl;
    }

    return 0;
}
