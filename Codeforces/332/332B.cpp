/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

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
ll dp[200010][3];
int idx[200010][3];
ll m;

ll arr[200010];

ll solve(ll n,ll k){
    if(n>=k*m && k){
        if(dp[n][k]==-1){
            dp[n][k]=max(solve(n-1,k),arr[n]-arr[n-m]+solve(n-m,k-1));
            if(dp[n][k]==solve(n-m,k-1)+arr[n]-arr[n-m])
                idx[n][k]=n-m+1;
            else
                idx[n][k]=idx[n-1][k];
        }

        return dp[n][k];
    }
    else
        return 0LL;
}

//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n>>m;

    memset(dp,-1LL,sizeof(dp));

    FOR(i,1,n+1){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }

    solve(n,2);

    int b=idx[n][2];
    int a=idx[b-1][1];

    FOR(i,1,a)
        if(arr[a+m-1]-arr[a-1]==arr[i+m-1]-arr[i-1]){
            a=i;
            break;
        }

    FOR(i,a+m,b)
        if(arr[b+m-1]-arr[b-1]==arr[i+m-1]-arr[i-1]){
            b=i;
            break;
        }

    cout<<a<<" "<<b<<endl;

    return 0;
}
