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
vi adj[100];
bool vis[100];
int cnt;
vi visV;

void dfs(int i){
    ++cnt;
    visV.pb(i);
    vis[i]=true;

    for(int x : adj[i])
        if(!vis[x])
            dfs(x);
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    REP(i,m){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    vector<vi > ans,twoV,oneV;
    FOR(i,1,n+1){
        if(!vis[i]){
            dfs(i);

            if(cnt>3){
                cout<<-1<<endl;
                return 0;
            }
            else if(cnt==3)
                ans.pb(visV);
            else if(cnt==2)
                twoV.pb(visV);
            else
                oneV.pb(visV);

            cnt=0;
            visV.clear();
        }
    }

    if(twoV.size()>oneV.size() || (oneV.size()-twoV.size())%3){
        cout<<-1<<endl;
        return 0;
    }
    else{
        REP(i,twoV.size()){
            twoV[i].pb(oneV[i][0]);
            ans.pb(twoV[i]);
        }

        vi temp;
        FOR(i,twoV.size(),oneV.size()){
            temp.pb(oneV[i][0]);

            if((i-twoV.size())%3==2){
                ans.pb(temp);
                temp.clear();
            }
        }

        for(auto v : ans){
            for(auto x : v)
                cout<<x<<" ";

            cout<<endl;
        }
    }

    return 0;
}
