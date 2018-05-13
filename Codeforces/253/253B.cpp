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
bool exists[5010];
int dp[5010];
//Main function
int main(){
    IOS;
    TIE;

    ifstream input;
    ofstream output;

    input.open("input.txt");
    output.open("output.txt");

    int n;
    input>>n;

    REP(i,n){
        int temp;
        input>>temp;
        exists[temp]=true;
        ++dp[temp];
    }

    DFOR(i,5000,1)
        dp[i]+=dp[i+1];

    int minVal=INT_MAX;
    FOR(i,1,5001)
        if(exists[i]){
            int idx=0;
            FOR(j,2*i+1,5001)
                if(exists[j]){
                    idx=j;
                    break;
                }

            minVal=min(minVal,dp[1]-dp[i]+dp[idx]);
        }

    output<<minVal<<endl;

    return 0;
}
