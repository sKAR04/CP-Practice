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

    int n;
    cin>>n;

    int arr[n],minVal=INT_MAX;
    REP(i,n){
        cin>>arr[i];
        minVal=min(minVal,arr[i]);
    }

    int idx;
    if(arr[0]==minVal){
        idx=0;
        DFOR(i,n-1,0)
            if(arr[i]==minVal)
                idx=i;
            else
                break;
    }
    else
        REP(i,n)
            if(arr[i]==minVal){
                idx=i;
                break;
            }

    int temp=idx,cnt=n-1;
    while(cnt){
        if(arr[temp]>arr[(temp+1)%n])
            break;

        temp=(temp+1)%n;
        --cnt;
    }

    if(cnt)
        idx=-1;
    else if(idx)
        idx=n-idx;

    cout<<idx<<endl;

    return 0;
}
