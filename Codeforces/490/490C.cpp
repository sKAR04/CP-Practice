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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
bool dp[1000010][2];
//Main function
int main(){
    IOS;
    TIE;

    string str;
    cin>>str;

    int a,b;
    cin>>a>>b;

    int len=str.length();
    int prevMod=0;
    REP(i,len){
        prevMod=(prevMod*10+(str[i]-48))%a;
        dp[i][0]=!prevMod;
    }

    int power10=1;
    prevMod=0;
    DFOR(i,len-1,0){
        prevMod=(power10*(str[i]-48)+prevMod)%b;
        power10=(power10*10)%b;
        dp[i][1]=!prevMod;
    }

    int idx=-1;
    REP(i,len-1)
        if(dp[i][0] && dp[i+1][1] && str[i+1]!=48){
            idx=i;
            break;
        }

    if(idx==-1)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<str.substr(0,idx+1)<<endl<<str.substr(idx+1)<<endl;
    }

    return 0;
}
