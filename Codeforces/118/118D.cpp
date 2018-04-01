/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

using namespace std;
#include <bits/stdc++.h>

//save time
#define endl '\n'
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  100000000LL
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

//Input methods
template <typename T>
void getFoo(T &x){
    x=0;
    register char c=gc();
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
}

template <typename T1,typename T2>
void getFoo(T1 &x,T2 &y){
    getFoo(x);
    getFoo(y);
}

template <typename T1,typename T2,typename T3>
void getFoo(T1 &x,T2 &y,T3 &z){
    getFoo(x);
    getFoo(y);
    getFoo(z);
}
//Declare all variables and methods needed between this comment and the next one(OCD lol)
ll dp[110][110][2];
int k1,k2;

ll solve(int n1,int n2,bool type){
    if(dp[n1][n2][type]==-1){
        ll ans=0LL;

        if(type){
            int minVal=min(n2,k2);
            FOR(i,1,minVal+1)
                ans=(ans+solve(n1,n2-i,0))%MOD;
        }
        else{
            int minVal=min(n1,k1);
            FOR(i,1,minVal+1)
                ans=(ans+solve(n1-i,n2,1))%MOD;
        }

        dp[n1][n2][type]=ans;
    }

    //cout<<n1<<" "<<n2<<" "<<type<<" "<<dp[n1][n2][type]<<endl;

    return dp[n1][n2][type];
}

//Main function
int main(){
    IOS;
    TIE;

    int n1,n2;
    cin>>n1>>n2>>k1>>k2;

    memset(dp,-1,sizeof(dp));

    dp[0][0][0]=dp[0][0][1]=0LL;

    FOR(i,1,n1+1){
        if(i<=k1)
            dp[i][0][0]=1LL;
        else
            dp[i][0][0]=0LL;

        dp[i][0][1]=0LL;
    }

    FOR(j,1,n2+1){
        if(j<=k2)
            dp[0][j][1]=1LL;
        else
            dp[0][j][1]=0LL;

        dp[0][j][0]=0LL;
    }

    cout<<(solve(n1,n2,0)+solve(n1,n2,1))%MOD<<endl;

    return 0;
}
