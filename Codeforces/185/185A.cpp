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
vll mtrx[2],base[2];
void mul(vll v1[2],vll v2[2]){
    ll a,b,c,d;
    a=(v1[0][0]*v2[0][0]+v1[0][1]*v2[1][0])%MOD;
    b=(v1[0][0]*v2[0][1]+v1[0][1]*v2[1][1])%MOD;
    c=(v1[1][0]*v2[0][0]+v1[1][1]*v2[1][0])%MOD;
    d=(v1[1][0]*v2[0][1]+v1[1][1]*v2[1][1])%MOD;

    mtrx[0][0]=a;
    mtrx[0][1]=b;
    mtrx[1][0]=c;
    mtrx[1][1]=d;
}

void printMtrx(vll mtrx[2]){
    REP(i,2){
        REP(j,2)
            cout<<mtrx[i][j]<<" ";
        cout<<endl;
        }
}

void power(ll n){
    if(n){
        power(n/2LL);
        mul(mtrx,mtrx);
        if(n&1LL)
            mul(mtrx,base);
    }
}
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;

    mtrx[0].pb(1);
    mtrx[0].pb(0);
    mtrx[1].pb(0);
    mtrx[1].pb(1);

    base[0].pb(3);
    base[0].pb(1);
    base[1].pb(1);
    base[1].pb(3);

    if(n){
        power(n);
        cout<<mtrx[0][0]<<endl;
    }
    else
        cout<<1<<endl;
    return 0;
}
