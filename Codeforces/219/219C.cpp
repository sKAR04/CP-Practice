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
int dp[110][4];
//Main function
int main(){
    IOS;
    TIE;

    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;

    if(k==2){
        bool flag=false;
        string str0="",str1="";
        REP(i,n){
            if(flag){
                str0+="A";
                str1+="B";
            }
            else{
                str0+="B";
                str1+="A";
            }

            flag=!flag;
        }

        int cnt0=0,cnt1=0;
        REP(i,n){
            if(str[i]!=str0[i])
                ++cnt0;
            if(str[i]!=str1[i])
                ++cnt1;
        }

        if(cnt1>cnt0)
            cout<<cnt0<<endl<<str0<<endl;
        else
            cout<<cnt1<<endl<<str1<<endl;
    }
    else{
        int cnt=0;
        str="$"+str+"$";
        int idx=1;
        while(idx<=n){
            int rIdx=idx;
            while(str[rIdx]==str[idx] && rIdx<=n)
                ++rIdx;

            cnt+=(rIdx-idx)/2;

            char rep;
            REP(i,k)
                if(str[idx-1]!=65+i && str[idx]!=65+i){
                    rep=65+i;
                    break;
                }

            if((rIdx-idx)%2)
                ++idx;

            while(idx!=rIdx){
                str[idx]=rep;
                idx+=2;
            }
        }

        str=str.substr(1,n);
        cout<<cnt<<endl<<str<<endl;
    }

    return 0;
}
