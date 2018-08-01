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
#define scan getFoo

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
struct Child{
    ll v,d,p;
};

Child c[4010];
bool flag[4010];
int n;

void triggerExit(int cur){
    if(flag[cur])
        return ;
    flag[cur]=true;
    vi triggered;

    FOR(j,cur+1,n)
        if(!flag[j]){
            c[j].p-=c[cur].d;

            if(c[j].p<0)
                triggered.pb(j);
        }

    for(int ch : triggered)
        triggerExit(ch);
}

void triggerVolume(int cur){
    ll curVol=c[cur].v;
    vi triggered;

    FOR(j,cur+1,n)
        if(curVol && !flag[j]){
            c[j].p-=curVol;
            --curVol;

            if(c[j].p<0)
                triggered.pb(j);
        }

    for(int ch : triggered)
        triggerExit(ch);
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n;

    REP(i,n)
        cin>>c[i].v>>c[i].d>>c[i].p;

    vi treated;
    REP(i,n)
        if(!flag[i]){
            treated.pb(i);
            triggerVolume(i);
        }

    cout<<treated.size()<<endl;
    for(int ch : treated)
        cout<<ch+1<<" ";
    cout<<endl;

    return 0;
}
