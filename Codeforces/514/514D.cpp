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
class SegTree{
public:
    int segTree[1<<19][5],arr[100010][5];
    void build(int low,int high,int pos){
        int mid=(low+high)>>1;
        if(low==high)
            REP(i,5)
                segTree[pos][i]=arr[mid][i];
        else{
            build(low,mid,2*pos+1);
            build(mid+1,high,2*pos+2);

            REP(i,5)
                segTree[pos][i]=max(segTree[2*pos+1][i],segTree[2*pos+2][i]);
        }
    }

    vi query(int low,int high,int pos,int qLow,int qHigh){
        vi ans(5,0);
        int mid=(low+high)>>1;

        if(low>qHigh || high<qLow)
            return ans;
        else if(qLow<=low && qHigh>=high)
            return vi(segTree[pos],segTree[pos]+5);
        else{
            vi left=query(low,mid,2*pos+1,qLow,qHigh),right=query(mid+1,high,2*pos+2,qLow,qHigh);
            REP(i,5)
                ans[i]=max(left[i],right[i]);

            return ans;
        }
    }
};

SegTree tree;
int n,m,k;
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m>>k;

    REP(i,n)
        REP(j,m)
            cin>>tree.arr[i][j];
    tree.build(0,n-1,0);

    vi ans(5,0);
    int l=0,maxLen=0;
    REP(i,n){
        while(l<=i){
            vi cur=tree.query(0,n-1,0,l,i);
            int sum=0;
            REP(j,5)
                sum+=cur[j];

            if(sum<=k){
                if(maxLen<i-l+1){
                    ans=cur;
                    maxLen=i-l+1;
                }
                break;
            }
            ++l;
        }
    }

    REP(i,m)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
