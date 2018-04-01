/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

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

//Input methods
template <typename T>
void getFoo(T &x){
    x=0;
    register char c=gc();
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
}

template <typename T1,typename T2>
void getFoo(T1 &x,T2 &y){
    getFoo(x);
    getFoo(y);
}

template <typename T1,typename T2,typename T3>
void getFoo(T1 &x,T2 &y,T3 &z){
    getFoo(x);
    getFoo(y);
    getFoo(z);
}
//Declare all variables and methods needed between this comment and the next one(OCD lol)
int totCnt;
int destCnt;

void solve(int sum,int qMarkCnt){
    if(!qMarkCnt){
        ++totCnt;
        if(!sum)
            ++destCnt;
    }
    else{
        solve(sum+1,qMarkCnt-1);
        solve(sum-1,qMarkCnt-1);
    }
}

//Main function
int main(){
    IOS;
    TIE;

    string str1,str2;
    cin>>str1>>str2;

    int len=str1.length();
    int sum=0;
    REP(i,len)
        if(str1[i]=='+')
            ++sum;
        else
            --sum;

    int qMarkCnt=0;
    REP(i,len)
        if(str2[i]=='+')
            --sum;
        else if(str2[i]=='-')
            ++sum;
        else
            ++qMarkCnt;

    solve(sum,qMarkCnt);

    double prob=(double)destCnt/(double)totCnt;
    cout<<setprecision(15)<<prob<<endl;

    return 0;
}
