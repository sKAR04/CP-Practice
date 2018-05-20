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
bool adjMtrx[26][26];
int inCnt[26];
int foo,bar;

int myCompare(string s0,string s1){
    int minLen=min(s0.length(),s1.length());

    REP(i,minLen)
        if(s0[i]!=s1[i]){
            foo=s0[i]-97;
            bar=s1[i]-97;

            return 1;
        }

    if(s0.size()>s1.size())
        return -1;
    else
        return 0;
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    string arr[n];
    REP(i,n)
        cin>>arr[i];

    REP(i,n)
        FOR(j,i+1,n){
            int flag=myCompare(arr[i],arr[j]);
            if(flag==1)
                adjMtrx[foo][bar]=true;
            else if(flag==-1){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }

    REP(i,26)
        REP(j,26)
            if(adjMtrx[i][j])
                ++inCnt[j];

    qi q;
    REP(i,26)
        if(!inCnt[i])
            q.push(i);

    vi ans;
    while(!q.E){
        int cur=q.front();
        ans.pb(cur);
        q.pop();

        REP(j,26)
            if(adjMtrx[cur][j]){
                adjMtrx[cur][j]=false;
                --inCnt[j];

                if(!inCnt[j])
                    q.push(j);
            }
    }

    REP(i,26)
        REP(j,26)
            if(adjMtrx[i][j]){
                cout<<"Impossible"<<endl;
                return 0;
            }

    string order="";
    bool exists[26]={};
    for(int x : ans){
        order+=(char)(97+x);
        exists[x]=true;
    }

    REP(i,26)
        if(!exists[i]){
            exists[i]=true;
            order+=(char)(97+i);
        }

    cout<<order<<endl;

    return 0;
}
