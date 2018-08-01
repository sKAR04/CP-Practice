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

//Main function
int main(){
    IOS;
    TIE;

    string str;
    cin>>str;

    int openCnt=0,closedCnt=0,hashCnt=0,len=str.length();
    REP(i,len)
        if(str[i]=='(')
            ++openCnt;
        else if(str[i]==')')
            ++closedCnt;
        else
            ++hashCnt;
    closedCnt+=hashCnt?(hashCnt-1):0;

    vi ans;
    REP(i,len)
        if(str[i]=='#' && hashCnt>1){
            str[i]=')';
            --hashCnt;
            ans.pb(1);
        }

    REP(i,len)
        if(str[i]=='#'){
            int remClosed=(openCnt-closedCnt>0)?openCnt-closedCnt:1;
            ans.pb(remClosed);

            string hash="";
            REP(i,remClosed)
                hash+=")";
            str=str.substr(0,i)+hash+str.substr(i+1);
        }

    len=str.length();
    int balance=0;
    bool flag=true;
    REP(i,len)
        if(str[i]=='(')
            ++balance;
        else{
            --balance;
            if(balance<0){
                flag=false;
                break;
            }
        }

    if(flag)
        for(int x : ans)
            cout<<x<<endl;
    else
        cout<<-1<<endl;

    return 0;
}
