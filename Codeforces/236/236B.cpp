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
#define MOD  1073741824LL
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
bool isPrime[110];
vi primes;

vi primeVect[101];
void sieve(){
    fill(isPrime,isPrime+110,true);

    isPrime[0]=isPrime[1]=false;
    FOR(i,2,101)
        if(isPrime[i])
            for(int j=2*i;j<101;j+=i)
                isPrime[j]=false;

    REP(i,100)
        if(isPrime[i])
            primes.pb(i);

    FOR(i,1,101){
        int cur=i;
        for(int p : primes){
            int cnt=0;
            while(cur%p==0){
                ++cnt;
                cur/=p;
            }

            primeVect[i].pb(cnt);
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;

    sieve();

    int a,b,c;
    cin>>a>>b>>c;

    ll totSum=0;
    int n=primes.size();
    FOR(i,1,a+1)
        FOR(j,1,b+1)
            FOR(k,1,c+1){
                ll tempFact=1LL;
                REP(l,n)
                    tempFact=(tempFact*(primeVect[i][l]+primeVect[j][l]+primeVect[k][l]+1))%MOD;

                totSum=(totSum+tempFact)%MOD;
            }

    cout<<totSum<<endl;

    return 0;
}
