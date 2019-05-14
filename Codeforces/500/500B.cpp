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
const int MAXN=3e2+10;
bool adj[MAXN][MAXN];
int arr[MAXN];
vector<vi> lists;
vi cur;
bool vis[MAXN];
int n;
void dfs(int x){
    vis[x]=true;
    cur.pb(x);
    FOR(i,1,n+1)
        if(!vis[i] && adj[x][i])
            dfs(i);
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n;

    FOR(i,1,n+1)
        cin>>arr[i];

    string str;
    FOR(i,1,n+1){
        cin>>str;
        FOR(j,1,n+1)
            adj[i][j]=str[j-1]-48;
    }

    FOR(i,1,n+1)
        if(!vis[i]){
            dfs(i);
            lists.pb(cur);
            cur.clear();
        }

    for(auto &v : lists){
        sort(all(v));
        vi tmp;
        for(int x : v)
            tmp.pb(arr[x]);
        sort(all(tmp));

        REP(i,v.size())
            arr[v[i]]=tmp[i];
    }

    FOR(i,1,n+1)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
