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
int dp[4010][4010];
int pos[4010][4010];
int arr[4010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    map<int,int> cnt;
    map<int,int> maxCnt;
    int ans=0;
    FOR(i,1,n+1){
        cin>>arr[i];
        cnt[arr[i]]=1;
        ++maxCnt[arr[i]];
        ans=max(ans,maxCnt[arr[i]]);
    }

    int sum=0;
    for(auto it=cnt.begin();it!=cnt.end();++it){
        it->S+=sum;
        sum=it->S;
    }

    FOR(i,1,n+1)
        arr[i]=cnt[arr[i]];

    REP(i,n+1)
        dp[0][i]=dp[i][0]=1;

    FOR(j,1,n+1){
        FOR(i,1,n+1)
            pos[i][j]=pos[i][j-1];

        FOR(i,1,j+1)
            if(arr[i]!=arr[j]){
                dp[i][j]=dp[pos[arr[j]][pos[arr[i]][j]]][pos[arr[i]][j]]+1;
                ans=max(ans,dp[i][j]);
            }
        pos[arr[j]][j]=j;
    }
    cout<<ans<<endl;

    return 0;
}
