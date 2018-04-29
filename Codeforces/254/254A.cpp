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
vi pos[5010];
//Main function
int main(){
    IOS;
    TIE;

    ifstream input;
    input.open("input.txt");

    ofstream output;
    output.open("output.txt");

    int n;
    input>>n;
    n*=2;

    REP(i,n){
        int temp;
        input>>temp;
        pos[temp].pb(i+1);
    }

    vi p1,p2;
    FOR(i,1,5010){
        int len=pos[i].size();
        if(len & 1){
            output<<-1<<endl;
            return 0;
        }

        REP(j,len)
            if(j & 1)
                p1.pb(pos[i][j]);
            else
                p2.pb(pos[i][j]);
    }

    n/=2;
    REP(i,n)
        output<<p1[i]<<" "<<p2[i]<<endl;
    return 0;
}
