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
#define REP(i,n) 	    for(ll i=0;i<(n);++i)
#define FOR(i,a,b)      for(ll i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(ll i=(a);i>=(b);--i)

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
map<int,int> cnt;
PQ<int,vi,greater<int> > q;
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    vector<pair<string,int> > ans;
    REP(i,n){
        string str;
        cin>>str;

        int x;
        if(str!="removeMin")
            cin>>x;

        if(str=="insert"){
            q.push(x);
            ++cnt[x];
            ans.pb(mp("insert",x));
        }
        else if(str=="getMin"){
            if(!cnt[x]){
                ans.pb(mp("insert",x));
                ++cnt[x];
                q.push(x);
            }

            while(q.top()!=x){
                ans.pb(mp("removeMin",0));
                --cnt[q.top()];
                q.pop();
            }

            ans.pb(mp("getMin",x));
        }
        else{
            if(q.E){
                ans.pb(mp("insert",0));
                ans.pb(mp("removeMin",0));
            }
            else{
                ans.pb(mp("removeMin",0));
                --cnt[q.top()];
                q.pop();
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto p : ans)
        if(p.F=="removeMin")
            cout<<p.F<<endl;
        else
            cout<<p.F<<" "<<p.S<<endl;

    return 0;
}
