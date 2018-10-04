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
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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

    int n,m;
    cin>>n>>m;

    string str1,str2;
    cin>>str1>>str2;

    bool flag=false;
    REP(i,n)
        if(str1[i]=='*'){
            flag=true;
            break;
        }

    if(flag){
        if(str1.size()<=str2.size()+1){
            int idx=-1;
            REP(i,n)
                if(str1[i]=='*'){
                    idx=i;
                    break;
                }

            string l="",r="";
            if(idx)
                l=str1.substr(0,idx);
            if(idx!=n-1)
                r=str1.substr(idx+1);

            REP(i,l.size())
                if(str2[i]!=l[i]){
                    flag=false;
                    break;
                }

            DFOR(i,r.size()-1,0)
                if(str2[i+m-r.size()]!=r[i]){
                    flag=false;
                    break;
                }
        }
        else
            flag=false;
    }
    else if(str1==str2)
        flag=true;

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
