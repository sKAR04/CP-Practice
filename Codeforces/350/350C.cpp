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
vector<string> ans;

void traverse(pi start,pi end){
    pi p=mp(end.F-start.F,end.S-start.S);
    if(p.F>0)
        ans.pb("1 "+to_string(p.F)+" R");
    else if(p.F)
        ans.pb("1 "+to_string(-p.F)+" L");

    if(p.S>0)
        ans.pb("1 "+to_string(p.S)+" U");
    else if(p.S)
        ans.pb("1 "+to_string(-p.S)+" D");
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    pair<int,pi > pos[n];
    REP(i,n){
        int x,y;
        cin>>x>>y;
        pos[i].F=abs(x)+abs(y);
        pos[i].S=mp(x,y);
    }
    sort(pos,pos+n);

    REP(i,n){
        pi cur=pos[i].S;
        traverse(mp(0,0),cur);
        ans.pb("2");
        traverse(cur,mp(0,0));
        ans.pb("3");
    }

    cout<<ans.size()<<endl;
    for(auto s : ans)
        cout<<s<<endl;

    return 0;
}
