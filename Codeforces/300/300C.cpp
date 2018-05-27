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
ll fact[1000010];
inline void genModulo(){
    fact[0]=1LL;
    FOR(i,1LL,1000010LL)
        fact[i]=(i*fact[i-1])%MOD;
}

ll power(ll base,ll exp){
    if(!exp)
        return 1LL;
    else{
        ll ans=power(base,exp/2);
        ans*=ans;
        ans%=MOD;

        if(exp & 1LL){
            ans*=base;
            ans%=MOD;
        }

        return ans;
    }
}

//Main function
int main(){
    IOS;
    TIE;

    genModulo();

    ll a,b,n;
    cin>>a>>b>>n;

    ll ans=0;
    REP(i,n+1){
        ll sum=a*i+b*(n-i);

        bool flag=true;
        while(sum){
            if(sum%10!=a && sum%10!=b){
                flag=false;
                break;
            }
            sum/=10LL;
        }

        if(flag){
            ll temp=fact[n];
            ll inv=power((fact[i]*fact[n-i])%MOD,MOD-2LL);

            ans+=temp*inv%MOD;
            ans%=MOD;
        }
    }

    cout<<ans<<endl;

    return 0;
}
