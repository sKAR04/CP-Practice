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
vi pos[100010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    REP(i,n){
        int temp;
        cin>>temp;
        pos[temp].pb(i);
    }

    vii ans;
    FOR(i,1,100010){
        int len=pos[i].size();
        if(len){
            if(len==1)
                ans.pb(mp(i,0));
            else{
                bool flag=true;
                int diff=pos[i][1]-pos[i][0];
                FOR(j,2,len)
                    if(pos[i][j]-pos[i][j-1]!=diff){
                        flag=false;
                        break;
                    }

                if(flag)
                    ans.pb(mp(i,diff));
            }
        }
    }

    cout<<ans.size()<<endl;
    for(pi p : ans)
        cout<<p.F<<" "<<p.S<<endl;

    return 0;
}
