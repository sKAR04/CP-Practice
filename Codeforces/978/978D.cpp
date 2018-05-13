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
ll n;
bool flag=true;
ll arr[100010];

ll check(ll diff){
    ll cnt=0;
    REP(i,n)
        if(arr[i]==arr[0]+i*diff+1 || arr[i]==arr[0]+i*diff-1)
            ++cnt;
        else if(arr[i]!=arr[0]+i*diff){
            flag=false;
            break;
        }

    return cnt;
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n;

    REP(i,n)
        cin>>arr[i];

    if(n<3)
        cout<<0<<endl;
    else{
        ll temp;
        ll ans=LLONG_MAX;

        ++arr[0];
        ++arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+2);
        else
            flag=true;

        --arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+1);
        else
            flag=true;

        --arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+2);
        else
            flag=true;
        ++arr[1];

        --arr[0];
        ++arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+1);
        else
            flag=true;

        --arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp);
        else
            flag=true;

        --arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+1);
        else
            flag=true;
        ++arr[1];

        --arr[0];
        ++arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+2);
        else
            flag=true;

        --arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+1);
        else
            flag=true;

        --arr[1];
        temp=check(arr[1]-arr[0]);
        if(flag)
            ans=min(ans,temp+2);
        else
            flag=true;
        ++arr[1];

        if(ans==LLONG_MAX)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}
