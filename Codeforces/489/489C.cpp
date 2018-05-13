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
string getMaxString(int sum,int len){
    string ans="";
    REP(i,sum/9)
        ans+="9";
    len-=(sum/9);
    sum%=9;

    if(len){
        ans+=(char)(sum+48);
        --len;
    }
    if(len)
        REP(i,len)
            ans+="0";

    return ans;
}
//Main function
int main(){
    IOS;
    TIE;
    int m,s;
    cin>>m>>s;

    bool flag=true;
    if(s==0 && m==1)
        cout<<0<<" "<<0<<endl;
    else if(s==0)
        cout<<-1<<" "<<-1<<endl;
    else if(s>9*m)
        cout<<-1<<" "<<-1<<endl;
    else{
        string maxStr=getMaxString(s,m);
        string minStr="";
        FOR(i,1,10)
            if(s-i+9<=9*m){
                string temp=getMaxString(s-i,m-1);
                reverse(all(temp));
                minStr=(char)(i+48)+temp;
                break;
            }

        cout<<minStr<<" "<<maxStr<<endl;
    }

    return 0;
}
