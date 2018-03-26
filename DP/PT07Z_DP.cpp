/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

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
#define TIE cin.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Input methods
template <typename T>
void getFoo(T &x){
    x=0;
    register char c=gc();
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
}

template <typename T1,typename T2>
void getFoo(T1 &x,T2 &y){
    getFoo(x);
    getFoo(y);
}

template <typename T1,typename T2,typename T3>
void getFoo(T1 &x,T2 &y,T3 &z){
    getFoo(x);
    getFoo(y);
    getFoo(z);
}
//Declare all variables and methods needed between this comment and the next one(OCD lol)
vi adj[100010];
int subTreeHeight[100010];
int superTreeHeight[100010];

int diameter;

void getSubTreeHeight(int parent,int i){
    int maxHeight=0;

    for(int x : adj[i])
        if(x!=parent){
            getSubTreeHeight(i,x);
            maxHeight=max(maxHeight,subTreeHeight[x]);
        }

    subTreeHeight[i]=maxHeight+1;
}

void dfs(int parent,int i){
    int maxHeight1=0;
    int maxHeight2=0;

    for(int x : adj[i])
        if(x!=parent)
            if(maxHeight1<subTreeHeight[x]){
                maxHeight2=maxHeight1;
                maxHeight1=subTreeHeight[x];
            }
            else
                maxHeight2=max(maxHeight2,subTreeHeight[x]);

    diameter=max(diameter,maxHeight1+max(maxHeight2,superTreeHeight[parent]+1));

    for(int x : adj[i])
        if(x!=parent){
            superTreeHeight[x]=superTreeHeight[i]+1;
            if(subTreeHeight[x]==maxHeight1)
                superTreeHeight[x]=max(maxHeight2+1,superTreeHeight[x]);
            else
                superTreeHeight[x]=max(maxHeight1+1,superTreeHeight[x]);
            dfs(i,x);
        }
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;

    REP(i,n-1){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    getSubTreeHeight(0,1);

    superTreeHeight[0]=-1;

    dfs(0,1);

    cout<<diameter<<endl;
    
    return 0;
}
