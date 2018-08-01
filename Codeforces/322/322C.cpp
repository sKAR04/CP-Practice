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

    int a,b;
    cin>>a>>b;

    string str;
    cin>>str;

    int xDisp=0,yDisp=0,len=str.length();
    REP(i,len)
        if(str[i]=='U')
            ++yDisp;
        else if(str[i]=='D')
            --yDisp;
        else if(str[i]=='L')
            --xDisp;
        else
            ++xDisp;

    int x=0,y=0;
    bool flag=false;
    REP(i,len){
        if(!xDisp && !yDisp){
            if(x==a && y==b)
                flag=true;
        }
        else if(!xDisp){
            if(x==a && (b-y)%yDisp==0 && (b-y)/yDisp>=0)
                flag=true;
        }
        else if(!yDisp){
            if((a-x)%xDisp==0 && b==y && (a-x)/xDisp>=0)
                flag=true;
        }
        else{
            if((a-x)%xDisp==0 && (b-y)%yDisp==0 && (a-x)/xDisp == (b-y)/yDisp && (a-x)/xDisp>=0)
                flag=true;
        }

        if(str[i]=='U')
            ++y;
        else if(str[i]=='D')
            --y;
        else if(str[i]=='L')
            --x;
        else
            ++x;
    }
    if(!xDisp && !yDisp){
        if(x==a && y==b)
            flag=true;
    }
    else if(!xDisp){
        if(x==a && (b-y)%yDisp==0 && (b-y)/yDisp>=0)
            flag=true;
    }
    else if(!yDisp){
        if((a-x)%xDisp==0 && b==y && (a-x)/xDisp>=0)
            flag=true;
    }
    else{
        if((a-x)%xDisp==0 && (b-y)%yDisp==0 && (a-x)/xDisp == (b-y)/yDisp && (a-x)/xDisp>=0)
            flag=true;
    }

    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
