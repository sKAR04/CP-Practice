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
#define REP(i,n) 	    for(ll i=0;i<(n);++i)
#define FOR(i,a,b)      for(ll i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(ll i=(a);i>=(b);--i)

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
bool present[1010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    while(cin>>n){
        present[n]=true;

        char c;
        cin>>c;
    }

    inr rMax;
    DFOR(i,1009,0)
        if(present[i]){
            rMax=i;
            break;
        }
    int l;
    bool flag=true;
    REP(i,1010)
        if(flag){
            if(present[i]){
                l=i;
                flag=false;
            }
        }
        else{
            if(!present[i]){
                if(i-1>l)
                    cout<<l<<"-"<<i-1;
                else
                    cout<<l;
                if(i!=rMax)
                    cout<<',';
                    
                flag=true;
            }
        }
    cout<<"\b\b"<<endl;

    return 0;
}
