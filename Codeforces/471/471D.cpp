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
int n,m;
int a[200010],b[200010],lps[200010];

inline void genLPS(){
    --n;
    --m;

    FOR(i,1,m){
        int len=lps[i-1];
        while(len && b[len]!=b[i])
            len=lps[len-1];

        if(b[len]==b[i])
            lps[i]=len+1;
    }
}

inline int countOccurrences(){
    int cnt=0;

    int patternPtr=0;
    REP(i,n){
        while(patternPtr && b[patternPtr]!=a[i])
            patternPtr=lps[patternPtr-1];

        if(b[patternPtr]==a[i])
            ++patternPtr;
        if(patternPtr==m){
            ++cnt;
            patternPtr=lps[patternPtr-1];
        }
    }

    return cnt;
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;

    REP(i,n)
        cin>>a[i];
    FOR(i,1,n)
        a[i-1]=a[i]-a[i-1];

    REP(i,m)
        cin>>b[i];
    FOR(i,1,m)
        b[i-1]=b[i]-b[i-1];

    if(m==1)
        cout<<n<<endl;
    else if(n==1)
        cout<<0<<endl;
    else{
        genLPS();
        cout<<countOccurrences()<<endl;
    }

    return 0;
}
