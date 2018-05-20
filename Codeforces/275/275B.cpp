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

//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    char grid[n][m];
    REP(i,n)
        REP(j,m)
            cin>>grid[i][j];

    REP(i,n){
        REP(j,m){
            REP(k,n){
                REP(l,m){
                    if(grid[i][j]=='B' && grid[k][l]=='B'){
                        bool flag=true;
                        if(i>=k){
                            FOR(fml,k,i+1)
                                if(grid[fml][l]!='B')
                                    flag=false;
                        }
                        else{
                            DFOR(fml,k,i)
                                if(grid[fml][l]!='B')
                                    flag=false;
                        }

                        if(j>=l){
                            FOR(fml,l,j+1)
                                if(grid[i][fml]!='B')
                                    flag=false;
                        }
                        else{
                            DFOR(fml,l,j)
                                if(grid[i][fml]!='B')
                                    flag=false;
                        }

                        if(!flag){
                            flag=true;
                            if(j>=l){
                                FOR(fml,l,j+1)
                                    if(grid[k][fml]!='B')
                                        flag=false;
                            }
                            else{
                                DFOR(fml,l,j)
                                    if(grid[k][fml]!='B')
                                        flag=false;
                            }

                            if(i>=k){
                                FOR(fml,k,i+1)
                                    if(grid[fml][j]!='B')
                                        flag=false;
                            }
                            else{
                                DFOR(fml,k,i)
                                    if(grid[fml][j]!='B')
                                        flag=false;
                            }

                            if(!flag){
                                cout<<"NO"<<endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
