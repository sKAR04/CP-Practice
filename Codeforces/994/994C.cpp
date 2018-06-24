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
struct Equation{
    int a,b,c;
};

Equation getEquation(pi p1,pi p2){
    Equation ans;
    ans.a=(p2.F-p1.F);
    ans.b=(p1.S-p2.S);
    ans.c=p1.F*(p2.S-p1.S)-p1.S*(p2.F-p1.F);


    if(ans.a<0){
        ans.a*=-1;
        ans.b*=-1;
        ans.c*=-1;
    }
    else if(!ans.a && ans.b<0){
        ans.a*=-1;
        ans.b*=-1;
        ans.c*=-1;
    }

    return ans;
}

int check(pi p,Equation foo){
    return foo.a*p.S+foo.b*p.F+foo.c;
}
//Main function
int main(){
    IOS;
    TIE;

    pi s1[4],s2[4];
    REP(i,4)
        cin>>s1[i].F>>s1[i].S;
    REP(i,4)
        cin>>s2[i].F>>s2[i].S;

    Equation sides1[4];
    REP(i,4)
        sides1[i]=getEquation(s1[i],s1[(i+1)%4]);

    Equation sides2[4];
    REP(i,4)
        sides2[i]=getEquation(s2[i],s2[(i+1)%4]);

    pi center1=mp((s1[0].F+s1[2].F)/2,(s1[0].S+s1[2].S)/2),center2=mp((s2[0].F+s2[2].F)/2,(s2[0].S+s2[2].S)/2);
    bool flag=false;
    REP(i,4)
        if(check(s2[i],sides1[0])*check(s2[i],sides1[2])<=0 && check(s2[i],sides1[1])*check(s2[i],sides1[3])<=0)
            flag=true;

    if(check(center2,sides1[0])*check(center2,sides1[2])<=0 && check(center2,sides1[1])*check(center2,sides1[3])<=0)
        flag=true;

    REP(i,4)
        if(check(s1[i],sides2[0])*check(s1[i],sides2[2])<=0 && check(s1[i],sides2[1])*check(s1[i],sides2[3])<=0)
            flag=true;
    if(check(center1,sides2[0])*check(center1,sides2[2])<=0 && check(center1,sides2[1])*check(center1,sides2[3])<=0)
        flag=true;

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
