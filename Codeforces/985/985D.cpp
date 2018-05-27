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
ll n,h;
ll bSearch0(ll low,ll high){
    ll mid=(low+high) >> 1;

    if(low<=high){
        ll val=mid*(mid+1LL)/2LL;
        if(val>n)
            return bSearch0(low,mid-1);
        else if(val==n)
            return mid;
        else
            return bSearch0(mid+1,high);
    }
    else
        return mid;
}

ll bSearch1(ll low,ll high){
    ll mid=(low+high) >> 1;

    if(low<=high){
        ll val=(h+mid)*(h+mid+1)-h*(h-1)/2LL;
        if(val>n)
            return bSearch1(low,mid-1);
        else if(val==n)
            return mid;
        else
            return bSearch1(mid+1,high);
    }
    else
        return mid;
}

ll bSearch2(ll low,ll high){
    ll mid=(low+high) >> 1;

    if(low<=high){
        ll val=(h+mid)*(h+mid+1)-h*(h-1)/2LL-(h+mid);
        if(val>n)
            return bSearch2(low,mid-1);
        else if(val==n)
            return mid;
        else
            return bSearch2(mid+1,high);
    }
    else
        return mid;
}

//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>h;

    ll root=bSearch0(0LL,2LL*MOD);
    if(root<=h){
        if(root*(root+1)/2LL==n)
            cout<<root<<endl;
        else
            cout<<root+1<<endl;
    }
    else{
        root=bSearch1(0LL,2LL*MOD);
        ll diff=n-((h+root)*(h+root+1)-h*(h-1)/2LL);
        if(!diff)
            cout<<h+2LL*root+1<<endl;
        else if(diff<=h+root+1)
            cout<<h+2LL*root+2<<endl;
        else{
            root=bSearch2(0LL,2LL*MOD);
            diff=n-((h+root)*(h+root+1)-h*(h-1)/2LL-(h+root));
            if(!diff)
                cout<<h+2LL*root<<endl;
            else
                cout<<h+2LL*root+1<<endl;
        }
    }

    return 0;
}
