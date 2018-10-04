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
const int MAXN=15000010;
int arr[300010],maxPrime[MAXN],cnt[MAXN];
inline void sieve(){
    for(int i=2;i*i<MAXN;++i)
        if(!maxPrime[i])
            for(int j=i*i;j<MAXN;j+=i)
                maxPrime[j]=i;

    FOR(i,2,MAXN)
        if(!maxPrime[i])
            maxPrime[i]=i;
}

int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    int gcdVal;
    REP(i,n){
        cin>>arr[i];
        if(i)
            gcdVal=gcd(gcdVal,arr[i]);
        else
            gcdVal=arr[i];
    }

    sieve();

    int ans=0;
    REP(i,n){
        arr[i]/=gcdVal;
        while(arr[i]>1){
            int curPrime=maxPrime[arr[i]];
            ++cnt[curPrime];
            ans=(ans>cnt[curPrime])?ans:cnt[curPrime];
            while(arr[i]%curPrime==0)
                arr[i]/=curPrime;
        }
    }

    if(!ans)
        cout<<-1<<endl;
    else
        cout<<n-ans<<endl;

    return 0;
}
