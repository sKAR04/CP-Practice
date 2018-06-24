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

    int n,m;
    cin>>n>>m;

    pi a[n],b[m];
    REP(i,n)
        cin>>a[i].F>>a[i].S;
    REP(i,m)
        cin>>b[i].F>>b[i].S;

    bool flag1=false,flag2=false;
    bool isCommon[10]={};

    REP(i,n){
        set<int> possible;
        REP(j,m)
            if((a[i].F==b[j].F && a[i].S==b[j].S) || (a[i].S==b[j].F && a[i].F==b[j].S))
                continue;
            else if(a[i].F==b[j].F || a[i].F==b[j].S)
                possible.insert(a[i].F);
            else if(a[i].S==b[j].F || a[i].S==b[j].S)
                possible.insert(a[i].S);

        if(possible.size()>1)
            flag1=true;

        for(auto it=possible.begin();it!=possible.end();++it)
            isCommon[*it]=true;
    }

    REP(j,m){
        set<int> possible;
        REP(i,n)
            if((b[j].F==a[i].F && b[j].S==a[i].S) || (b[j].S==a[i].F && b[j].F==a[i].S))
                continue;
            else if(b[j].F==a[i].F || b[j].F==a[i].S)
                possible.insert(b[j].F);
            else if(b[j].S==a[i].F || b[j].S==a[i].S)
                possible.insert(b[j].S);

        if(possible.size()>1)
            flag2=true;

        for(auto it=possible.begin();it!=possible.end();++it)
            isCommon[*it]=true;
    }

    int commonCnt=0;
    int commonNum=0;
    REP(i,10)
        if(isCommon[i]){
            ++commonCnt;
            commonNum=i;
        }

    if(commonCnt==1)
        cout<<commonNum<<endl;
    else if(!flag1 && !flag2)
        cout<<0<<endl;
    else
        cout<<-1<<endl;

    return 0;
}
