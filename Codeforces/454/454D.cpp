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
int dp[110][(1<<17)],b[110][(1<<17)];
int bit[60],arr[110],primeMask[60];

void precalc(){
    bit[2]=bit[3]=bit[5]=bit[7]=bit[11]=bit[13]=bit[17]=bit[19]=bit[23]=1;
    bit[29]=bit[31]=bit[37]=bit[41]=bit[43]=bit[47]=bit[53]=bit[59]=1;
    bit[0]=bit[1]=-1;

    FOR(i,2,60){
        bit[i]+=bit[i-1];
        int temp=i;
        FOR(j,2,i+1)
            if(temp%j==0){
                while(temp%j==0)
                    temp/=j;
                primeMask[i]|=(1<<bit[j]);
            }
    }

    FOR(i,1,101)
        REP(j,(1<<17)){
            dp[i][j]=INF;
            b[i][j]=1;
        }
}
//Main function
int main(){
    IOS;
    TIE;

    precalc();

    int n;
    cin>>n;

    FOR(i,1,n+1)
        cin>>arr[i];

    FOR(i,1,n+1){
        FOR(j,1,60){
            int revMask=(~primeMask[j])&((1<<17)-1);
            for(int k=revMask;k;k=(k-1)&revMask)
                if(dp[i][k|primeMask[j]]>dp[i-1][k]+abs(arr[i]-j)){
                    dp[i][k|primeMask[j]]=dp[i-1][k]+abs(arr[i]-j);
                    b[i][k|primeMask[j]]=j;
                }
        }
    }

    int curMin=INF,mask=0;
    REP(i,(1<<17))
        if(curMin>dp[n][i]){
            curMin=dp[n][i];
            mask=i;
        }

    di ans;
    DFOR(i,n,1){
        ans.push_front(b[i][mask]);
        mask&=(~(primeMask[b[i][mask]])&((1<<17)-1));
    }

    REP(i,n)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
