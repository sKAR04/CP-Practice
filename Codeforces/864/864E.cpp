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
int dp[110][2050];
int t[110],d[110],p[110],idx[110];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    pair<pi,pi> fml[n+1];
    FOR(i,1,n+1){
        cin>>fml[i].F.S>>fml[i].F.F>>fml[i].S.F;
        fml[i].S.S=i;
    }
    sort(fml+1,fml+n+1);
    FOR(i,1,n+1){
        d[i]=fml[i].F.F;
        t[i]=fml[i].F.S;
        p[i]=fml[i].S.F;
        idx[i]=fml[i].S.S;
    }

    FOR(i,1,n+1){
        REP(j,2001){
            dp[i][j]=dp[i-1][j];
            if(j<d[i] && j>=t[i])
                dp[i][j]=(dp[i][j]>dp[i-1][j-t[i]]+p[i])?dp[i][j]:dp[i-1][j-t[i]]+p[i];
        }
    }

    int ans=0,endTime=0,item=n;
    REP(i,2001){
        if(dp[n][i]>ans){
            ans=dp[n][i];
            endTime=i;
        }
    }
    cout<<ans<<endl;

    di items;
    while(item && endTime){
        if(endTime<d[item] && endTime>=t[item] && dp[item][endTime]==dp[item-1][endTime-t[item]]+p[item]){
            items.push_front(idx[item]);
            endTime-=t[item];
            --item;
        }
        else
            --item;
    }
    cout<<items.size()<<endl;
    for(int i : items)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
