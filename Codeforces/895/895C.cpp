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
ll bit[70],cnt[100],power[100010][2],dp[1<<21][2];

void precalc(){
    bit[2]=bit[3]=bit[5]=bit[7]=bit[11]=bit[13]=bit[17]=bit[19]=bit[23]=bit[29]=1;
    bit[31]=bit[37]=bit[41]=bit[43]=bit[47]=bit[53]=bit[59]=bit[61]=bit[67]=1;
    bit[0]=-1;

    FOR(i,1,70)
        bit[i]+=bit[i-1];

    power[0][0]=1;
    power[1][0]=power[1][1]=1;
    FOR(i,2,100010)
        power[i][0]=power[i][1]=(power[i-1][0]*2)%MOD;
}
//Main function
int main(){
    IOS;
    TIE;

    precalc();

    int n;
    cin>>n;

    REP(i,n){
        int ai;
        cin>>ai;
        ++cnt[ai];
    }

    dp[0][0]=1;
    FOR(i,1,71){
        int curMask=0,temp=i;
        FOR(j,2,i+1)
            if(temp%j==0){
                while(temp%j==0){
                    temp/=j;
                    if(curMask & (1<<bit[j]))
                        curMask&=(~(1<<bit[j]));
                    else
                        curMask|=(1<<bit[j]);
                }
            }

        if(!curMask){
            REP(mask,1<<20)
                dp[mask][1]=(dp[mask][0]*power[cnt[i]+1][0])%MOD;
            REP(j,1<<20){
                dp[j][0]=dp[j][1];
                dp[j][1]=0;
            }
        }
        else if(cnt[i]){
            REP(mask,1<<20)
                dp[mask][1]=(dp[mask][0]*power[cnt[i]][0])%MOD;
            REP(mask,1<<20)
                dp[mask^curMask][1]=(dp[mask^curMask][1]+dp[mask][0]*power[cnt[i]][1])%MOD;
            REP(j,1<<20){
                dp[j][0]=dp[j][1];
                dp[j][1]=0;
            }
        }
    }
    cout<<(dp[0][0]-1+MOD)%MOD<<endl;

    return 0;
}
