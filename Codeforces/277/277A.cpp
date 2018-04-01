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
#define TIE cin.tie(NULL);cout.tie(NULL)

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
int n,m;
bool adjMtrx[110][110];
vi languages[110],emp[110];
bool vis[110];

void dfs(int cur){
    vis[cur]=true;

    FOR(i,1,n+1)
        if(!vis[i] && adjMtrx[cur][i])
            dfs(i);
}

//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;

    int cnt=0;
    FOR(i,1,n+1){
        int temp;
        cin>>temp;

        cnt+=temp;
        while(temp--){
            int temp1;
            cin>>temp1;
            languages[temp1].pb(i);
            emp[i].pb(temp1);
        }
    }

    int ans=-1;

    if(cnt){
        FOR(i,1,m+1)
            for(auto e1 : languages[i])
                for(auto e2 : languages[i])
                    adjMtrx[e1][e2]=true;

        FOR(i,1,n+1)
            if(!vis[i]){
                dfs(i);
                ++ans;
            }
    }
    else
        ans=n;

    cout<<ans<<endl;

    return 0;
}
