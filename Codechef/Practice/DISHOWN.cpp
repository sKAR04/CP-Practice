//Strike me down and I shall become stronger, than you can possibly imagine

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
#define vii vector<pair<int,int> >
#define pb 	push_back
#define pf push_front

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Variables and Functions required
int dishes[10010],rep[10010],sz[10010],maxIdx[10010];

inline int getRep(int cur){
    while(cur!=rep[cur])
        cur=rep[cur];
    return cur;
}

inline void setUnion(int x,int y){
    if(sz[x]>sz[y]){
        sz[x]+=sz[y];
        rep[y]=x;
    }
    else{
        sz[y]+=sz[x];
        rep[x]=y;
    }
}

inline void solve(){
    int n;
    cin>>n;

    FOR(i,1,n+1){
        cin>>dishes[i];
        maxIdx[i]=rep[i]=i;
        sz[i]=1;
    }

    int q;
    cin>>q;

    while(q--){
        int type;
        cin>>type;

        if(!type){
            int x,y;
            cin>>x>>y;

            int repX=getRep(x),repY=getRep(y);
            if(maxIdx[repX]==maxIdx[repY])
                cout<<"Invalid query!"<<endl;
            else if(dishes[maxIdx[repX]]!=dishes[maxIdx[repY]]){
                setUnion(repX,repY);
                if(dishes[maxIdx[repX]]<dishes[maxIdx[repY]])
                    maxIdx[repX]=maxIdx[repY];
                else
                    maxIdx[repY]=maxIdx[repX];
            }
        }
        else{
            int x;
            cin>>x;
            cout<<maxIdx[getRep(x)]<<endl;
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
