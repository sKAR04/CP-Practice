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
const int MAXN=0;
ll gcd(ll a,ll b){
    if(!b)
        return a;
    return gcd(b,a%b);
}
//Main function
int main(){
    IOS;
    TIE;

    ll n,m,k;
    cin>>n>>m>>k;

    if((n*m*2)%k==0){
        cout<<"YES"<<endl;
        ll x,y,g;
        if(k&1LL){
            g=gcd(n,k);
            if(g>1){
                x=n*2/g;
                k/=g;
                y=m/k;
            }
            else{
                x=n;
                y=(2*m/k);
            }
        }
        else{
            k>>=1;
            g=gcd(n,k);
            x=n/g;
            k=k/g;
            y=m/k;
        }
        cout<<0<<" "<<0<<endl;
        cout<<x<<" "<<0<<endl;
        cout<<0<<" "<<y<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
