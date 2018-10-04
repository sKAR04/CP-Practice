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

//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    pi arr[n];
    REP(i,n)
        cin>>arr[i].F>>arr[i].S;

    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    int firstMax=max(arr[0].F,arr[1].F),secondMax=min(arr[0].F,arr[1].F);
    FOR(i,2,n)
        if(arr[i].F>=firstMax){
            secondMax=firstMax;
            firstMax=arr[i].F;
        }
        else if(arr[i].F>secondMax)
            secondMax=arr[i].F;

    int firstMin=min(arr[0].S,arr[1].S),secondMin=max(arr[0].S,arr[1].S);
    FOR(i,2,n)
        if(arr[i].S<=firstMin){
            secondMin=firstMin;
            firstMin=arr[i].S;
        }
        else if(arr[i].S<secondMin)
            secondMin=arr[i].S;

    int ans=0;
    REP(i,n){
        int lMax=(arr[i].F==firstMax)?secondMax:firstMax;
        int rMin=(arr[i].S==firstMin)?secondMin:firstMin;
        ans=(ans>(rMin-lMax))?ans:(rMin-lMax);
    }
    cout<<ans<<endl;

    return 0;
}
