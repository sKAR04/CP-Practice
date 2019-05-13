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
const int MAXN=1e5+10;
int firstTime[MAXN],lastTime[MAXN],arr[MAXN],n,k;
bool check(int p1,int p2){
    if(p2<1 || p2>n)
        return false;
    if(p1==p2)
        return firstTime[p1]==0;
    else if(!firstTime[p2] || !firstTime[p1])
        return true;
    else
        return firstTime[p1]>lastTime[p2];
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>k;

    FOR(i,1,k+1)
        cin>>arr[i];

    DFOR(i,k,1)
        if(!lastTime[arr[i]])
            lastTime[arr[i]]=i;

    FOR(i,1,k+1)
        if(!firstTime[arr[i]])
            firstTime[arr[i]]=i;

    firstTime[0]=lastTime[0]=firstTime[n+1]=lastTime[n+1]=INF;

    int ans=0;
    FOR(i,1,n+1)
        FOR(j,i-1,i+2)
            ans+=check(i,j);
    cout<<ans<<endl;

    return 0;
}
