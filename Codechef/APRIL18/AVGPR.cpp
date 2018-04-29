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
inline void solve(){
    ll cntPos[3010];
    ll cntNeg[3010];

    fill(cntPos,cntPos+3010,0);
    fill(cntNeg,cntNeg+3010,0);

    int n;
    cin>>n;

    REP(i,n){
        int temp;
        cin>>temp;

        if(temp>=0)
            ++cntPos[temp];
        else
            ++cntNeg[temp*-1];
    }

    ll ans=0;
    REP(i,1010)
        FOR(j,i+1,1010)
            if(cntPos[(i+j)/2] && (i+j)%2==0)
                ans+=(cntPos[i]*cntPos[j]);

    REP(i,1010)
        FOR(j,i+1,1010)
            if(cntNeg[(i+j)/2] && (i+j)%2==0)
                ans+=(cntNeg[i]*cntNeg[j]);

    REP(i,1010)
        FOR(j,i+1,1010)
            if(cntNeg[(j-i)/2] && (j-i)%2==0)
                ans+=(cntPos[i]*cntNeg[j]);

    REP(i,1010)
        FOR(j,i+1,1010)
            if(cntPos[(j-i)/2] && (j-i)%2==0)
                ans+=(cntPos[j]*cntNeg[i]);

    if(cntPos[0])
        FOR(i,1,1010)
            ans+=(cntPos[i]*cntNeg[i]);
            
    REP(i,1010){
        ans+=(cntPos[i]*(cntPos[i]-1)/2);
        ans+=(cntNeg[i]*(cntNeg[i]-1)/2);
    }

    cout<<ans<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
