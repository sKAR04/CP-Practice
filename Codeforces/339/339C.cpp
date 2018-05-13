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
bool weight[11];
int m;

void dfs(vi cur,int prev,int leftPan,int rightPan){
    int curSize=cur.size();
    if(curSize==m){
        cout<<"YES"<<endl;
        for(int x : cur)
            cout<<x<<" ";
        cout<<endl;

        exit(0);
    }
    else{
        if(curSize & 1){
            FOR(i,1,11)
                if(i!=prev && weight[i] && rightPan+i>leftPan){
                    cur.pb(i);
                    dfs(cur,i,leftPan,rightPan+i);
                    cur.pop_back();
                }
        }
        else{
            FOR(i,1,11)
                if(i!=prev && weight[i] && leftPan+i>rightPan){
                    cur.pb(i);
                    dfs(cur,i,leftPan+i,rightPan);
                    cur.pop_back();
                }
        }
    }
}

//Main function
int main(){
    IOS;
    TIE;

    string str;
    cin>>str>>m;

    FOR(i,1,11)
        weight[i]=str[i-1]-48;

    vi temp;
    dfs(temp,0,0,0);

    cout<<"NO"<<endl;

    return 0;
}
