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

//Declare all variables and methods needed between this comment and the next one(OCD lol)
vi mobiusFact;
bool isPrime[10010];
int mobiusSum[100000010];

inline void sieve(){
    fill(isPrime,isPrime+10010,true);
    isPrime[0]=isPrime[1]=false;

    REP(i,10010)
        if(isPrime[i]){
            mobiusFact.pb(i*i);
            for(int j=2*i;j<10010;j+=i)
                isPrime[j]=false;
        }
}

inline void mobius(){
    for(int m : mobiusFact)
        for(int j=m;j<100000010;j+=m)
            mobiusSum[j]=1;

    FOR(i,1,100000010)
        mobiusSum[i]+=mobiusSum[i-1];
}
//Main function
int main(){
    IOS;
    TIE;

    sieve();

    mobius();

    while(1){
        int a,b;
        cin>>a>>b;

        if(!a && !b)
            break;

        cout<<mobiusSum[b]-mobiusSum[a-1]<<endl;
    }
    return 0;
}
