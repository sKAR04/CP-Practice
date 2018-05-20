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

    vector<long double> angles;
    REP(i,n){
        int x,y;
        cin>>x>>y;

        long double angle;
        if(!x)
            if(!y)
                angle=0;
            else
                angle=90;
        else
            angle=atan((long double)abs(y)/(long double)abs(x))*180/PI;

        if(x>=0 && y>=0)
            angle+=0;
        else if(y>=0)
            angle=180-angle;
        else if(x>=0)
            angle=360-angle;
        else
            angle+=180;

        angles.pb(angle);
    }

    sort(all(angles));

    int len=angles.size();
    long double ans=360-(angles[len-1]-angles[0]);
    REP(i,len-1)
        ans=max(ans,angles[i+1]-angles[i]);

    if(n==1)
        cout<<0<<endl;
    else
        cout<<setprecision(20)<<360-ans<<endl;

    return 0;
}
