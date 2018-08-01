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
ll dp[1 << 19][100];
ll power[19];
dll n;
ll getDigits(ll temp){
    ll cnt=0;
    while(temp){
        n.push_front(temp%10LL);
        temp/=10LL;
    }
    return n.size();
}
//Main function
int main(){
    //IOS;
    TIE;

    ll temp,m;
    cin>>temp>>m;

    power[0]=1LL;
    FOR(i,1,19)
        power[i]=power[i-1]*10LL;

    ll digits=getDigits(temp);
    dp[0][0]=1LL;
    REP(mask,(1LL << digits)){
        ll curBits=__builtin_popcountll(mask);

        bool exists[10]={};
        if(curBits==digits-1LL){
            REP(i,digits)
                if(!(mask&(1LL<<i)) && n[digits-i-1LL] && !exists[n[digits-i-1LL]]){
                    exists[n[digits-i-1LL]]=true;
                    REP(j,m)
                        dp[mask|(1<<i)][(power[curBits]*n[digits-i-1LL]+j)%m]+=dp[mask][j];
                }
        }
        else{
            REP(i,digits)
                if(!(mask&(1LL<<i)) && !exists[n[digits-i-1LL]]){
                    exists[n[digits-i-1LL]]=true;
                    REP(j,m)
                        dp[mask|(1LL<<i)][(power[curBits]*n[digits-i-1LL]+j)%m]+=dp[mask][j];
                }
        }
    }
    cout<<dp[(1<<digits)-1][0]<<endl;
    return 0;
}
