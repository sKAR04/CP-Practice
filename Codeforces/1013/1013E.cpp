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
int arr[5010];
int dp[5010][5010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    FOR(i,1,n+1)
        cin>>arr[i];
    arr[0]=arr[n+1]=-INF;

    int ans=INF;
    FOR(i,1,n+1){
        if(arr[i]<=arr[i-1])
            dp[i][1]+=arr[i-1]-arr[i]+1;
        if(arr[i]<=arr[i+1])
            dp[i][1]+=arr[i+1]-arr[i]+1;
        ans=(ans>dp[i][1])?dp[i][1]:ans;
    }
    cout<<ans<<" ";

    int up=n/2+(n&1);
    FOR(i,2,up+1){
        int ans=INF,tmp=INF;
        FOR(j,2*i-1,n+1){
            dp[j][i]=dp[j-2][i-1];
            int mn=(arr[j-1]>arr[j-2]-1)?arr[j-2]-1:arr[j-1];
            if(mn>=arr[j])
                dp[j][i]+=(mn-arr[j]+1);
            if(arr[j+1]>=arr[j])
                dp[j][i]+=(arr[j+1]-arr[j]+1);
            dp[j][i]=(dp[j][i]>tmp+dp[j][1])?(tmp+dp[j][1]):dp[j][i];
            tmp=(tmp>dp[j-2][i-1])?dp[j-2][i-1]:tmp;
            ans=(ans>dp[j][i])?dp[j][i]:ans;
        }
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}
