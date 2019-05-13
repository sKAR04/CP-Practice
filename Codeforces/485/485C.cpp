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
const int MAXN=0;
void solve(){
    ll l,r;
    cin>>l>>r;

    bool n1[63],n2[63],n[63];
    REP(i,63){
        n1[i]=l&1LL;
        n2[i]=r&1LL;
        l>>=1LL;
        r>>=1LL;
    }

    bool flag=false;
    DFOR(i,62,0)
        if(flag)
            n[i]=1;
        else{
            if(n1[i]==n2[i])
                n[i]=n1[i];
            else{
                n[i]=0;
                flag=true;
            }
        }

    int cnt1=0,cnt2=0;
    REP(i,63)
        cnt1+=n[i];
    REP(i,63)
        cnt2+=n2[i];

    if(cnt2>cnt1)
        REP(i,63)
            n[i]=n2[i];

    ll ans=0LL,pow2=1LL;
    REP(i,63){
        ans+=(pow2*n[i]);
        pow2<<=1LL;
    }
    cout<<ans<<endl;
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
