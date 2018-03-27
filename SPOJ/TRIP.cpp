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
#define TIE cin.tie(NULL)

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
string str0,str1;
set<string> dp[100][100];

inline void solve(){
    cin>>str0>>str1;

    int n0=str0.size();
    int n1=str1.size();

    str0=" "+str0;
    str1=" "+str1;

    REP(i,n0+1)
        REP(j,n1+1)
            dp[i][j].clear();

    FOR(i,1,n0+1)
        FOR(j,1,n1+1)
            if(str0[i]==str1[j])
                if(dp[i-1][j-1].E){
                    string temp="";
                    temp+=str0[i];
                    dp[i][j].insert(temp);
                }
                else
                    for(auto it=dp[i-1][j-1].begin();it!=dp[i-1][j-1].end();++it)
                        dp[i][j].insert((*it)+str0[i]);
            else{
                int temp=0;
                if(!dp[i-1][j].E)
                    temp=max(temp,(int)((*(dp[i-1][j].begin())).size()));
                if(!dp[i][j-1].E)
                    temp=max(temp,(int)((*(dp[i][j-1].begin())).size()));

                if(!dp[i-1][j].E)
                    if(temp==(int)((*(dp[i-1][j].begin())).size()))
                        for(auto it=dp[i-1][j].begin();it!=dp[i-1][j].end();++it)
                            dp[i][j].insert(*it);

                if(!dp[i][j-1].E)
                    if(temp==(int)((*(dp[i][j-1].begin())).size()))
                        for(auto it=dp[i][j-1].begin();it!=dp[i][j-1].end();++it)
                            dp[i][j].insert(*it);
            }

    for(auto it=dp[n0][n1].begin();it!=dp[n0][n1].end();++it)
        cout<<*it<<endl;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
