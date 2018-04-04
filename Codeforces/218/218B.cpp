/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <iostream>
#include <queue>
#include <vector>

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
#define pq priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)

//Main function
int main(){
    IOS;
    TIE;

    pq<int,vi,greater<int> > minQ;
    pq<int> maxQ;

    int n,m;
    cin>>n>>m;

    REP(i,m){
        int temp;
        cin>>temp;
        minQ.push(temp);
        maxQ.push(temp);
    }

    int minCnt=0;
    int maxCnt=0;

    REP(i,n){
        minCnt+=minQ.top();
        maxCnt+=maxQ.top();

        if(minQ.top()==1)
            minQ.pop();
        else{
            int temp=minQ.top();
            minQ.pop();
            minQ.push(temp-1);
        }

        if(maxQ.top()==1)
            maxQ.pop();
        else{
            int temp=maxQ.top();
            maxQ.pop();
            maxQ.push(temp-1);
        }
    }

    cout<<maxCnt<<" "<<minCnt<<endl;

    return 0;
}
