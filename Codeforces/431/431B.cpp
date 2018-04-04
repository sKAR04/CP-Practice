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

//Main function
int main(){
    IOS;
    TIE;

    int happiness[6][6];
    FOR(i,1,6)
        FOR(j,1,6)
            cin>>happiness[i][j];

    vi order{1,2,3,4,5};

    int maxSum=0;
    do{
        int tempSum=0;
        tempSum+=happiness[order[0]][order[1]]+happiness[order[1]][order[0]]+happiness[order[2]][order[3]]+happiness[order[3]][order[2]];
        tempSum+=happiness[order[1]][order[2]]+happiness[order[2]][order[1]]+happiness[order[3]][order[4]]+happiness[order[4]][order[3]];
        tempSum+=happiness[order[2]][order[3]]+happiness[order[3]][order[2]];
        tempSum+=happiness[order[3]][order[4]]+happiness[order[4]][order[3]];

        maxSum=max(maxSum,tempSum);
    }
    while(next_permutation(all(order)));

    cout<<maxSum<<endl;

    return 0;
}
