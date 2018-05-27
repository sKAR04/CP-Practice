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
string str;
ll alpha[26];
ll arr[100010];

ll solve(ll low,ll high){
    ll mid=(low+high) >> 1;

    if(low==high)
        return 0LL;
    else{
        ll ans=solve(low,mid)+solve(mid+1,high);
        map<ll,ll[26]> lCnt,rCnt;

        DFOR(i,mid,low)
            ++((lCnt[arr[mid]-arr[i]])[str[i-1]-97]);
        FOR(i,mid+1,high+1)
            ++((rCnt[arr[i-1]-arr[mid]])[str[i-1]-97]);

        for(auto it=lCnt.begin();it!=lCnt.end();++it)
            REP(i,26)
                ans+=(((it->S)[i])*((rCnt[-it->F])[i]));

        return ans;
    }
}
//Main function
int main(){
    IOS;
    TIE;

    REP(i,26)
        cin>>alpha[i];

    cin>>str;

    ll len=str.length();
    FOR(i,1,len+1)
        arr[i]=alpha[str[i-1]-97];

    FOR(i,1,100010)
        arr[i]+=arr[i-1];

    cout<<solve(1,len)<<endl;

    return 0;
}
