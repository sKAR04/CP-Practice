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
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
vi adj[510];
int rep[100010],sz[100010],c[100010];
int d[510][510],type[510];

int getRep(int i){
    while(rep[i]!=i)
        i=rep[i];

    return i;
}

void setUnion(int v1,int v2){
    int rep1=getRep(v1),rep2=getRep(v2);
    if(sz[rep1]>sz[rep2]){
        sz[rep1]+=sz[rep2];
        rep[rep2]=rep1;
    }
    else{
        sz[rep2]+=sz[rep1];
        rep[rep1]=rep2;
    }
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m,k;
    cin>>n>>m>>k;

    FOR(i,1,k+1)
        FOR(j,1,k+1)
            if(i!=j)
                d[i][j]=INF;

    FOR(i,1,k+1)
        cin>>type[i];

    int cur=1;
    FOR(i,1,k+1){
        FOR(j,cur,cur+type[i])
            c[j]=i;
        cur+=type[i];
    }

    FOR(i,1,n+1){
        sz[i]=1;
        rep[i]=i;
    }

    REP(i,m){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        d[c[v1]][c[v2]]=d[c[v2]][c[v1]]=min(d[c[v1]][c[v2]],w);

        if(!w)
            setUnion(v1,v2);
    }

    int idx=1;
    bool flag=true;
    FOR(i,1,k+1){
        set<int> reps;
        FOR(j,idx,idx+type[i])
            reps.insert(getRep(j));

        if(reps.size()>1)
            flag=false;
        idx+=type[i];
    }

    if(flag){
        cout<<"Yes"<<endl;

        FOR(x,1,k+1)
            FOR(y,1,k+1)
                FOR(z,1,k+1)
                    if(d[y][x]+d[x][z]<d[y][z])
                        d[y][z]=d[y][x]+d[x][z];

        FOR(i,1,k+1){
            FOR(j,1,k+1)
                if(d[i][j]==INF)
                    cout<<-1<<" ";
                else
                    cout<<d[i][j]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"No"<<endl;

    return 0;
}
