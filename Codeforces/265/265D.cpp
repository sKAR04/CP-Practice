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
bool isPrime[100010];
int dp[100010];

void sieve(){
    fill(isPrime,isPrime+100010,true);
    isPrime[0]=isPrime[1]=false;
    REP(i,100010)
        if(isPrime[i])
            for(ll j=2*i;j<100010;j+=i)
                isPrime[j]=false;
}
//Main function
int main(){
    IOS;
    TIE;

    sieve();

    int n;
    cin>>n;

    int ans=0;
    REP(i,n){
        int x;
        cin>>x;

        int root=sqrt(x);
        vi factors;
        FOR(j,1,root+1)
            if(x%j==0){
                if(isPrime[j])
                    factors.pb(j);
                if(isPrime[x/j])
                    factors.pb(x/j);
            }


        int prevLen=0;
        for(int f : factors)
            prevLen=max(prevLen,dp[f]);
        for(int f : factors)
            dp[f]=prevLen+1;
        ans=max(ans,prevLen+1);
    }
    cout<<ans<<endl;

    return 0;
}
