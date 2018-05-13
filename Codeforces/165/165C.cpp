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

//Main function
int main(){
    IOS;
    TIE;

    int k;
    cin>>k;

    string str;
    cin>>str;

    vll ones;
    ones.pb(-1LL);

    ll len=str.length();
    REP(i,len)
        if(str[i]==49)
            ones.pb(i);

    ones.pb(len);

    ll ans=0;
    if(ones.size()>=k+2){
        int idx=ones.size()-k;
        if(k)
            FOR(i,1,idx)
                ans+=(ones[i]-ones[i-1])*(ones[i+k]-ones[i+k-1]);
        else if(ones.size()!=2)
            FOR(i,1,idx){
                ll temp=ones[i]-ones[i-1]-1;
                ans+=temp*(temp+1)/2;
            }
        else
            ans+=len*(len+1)/2;
    }

    cout<<ans<<endl;

    return 0;
}
