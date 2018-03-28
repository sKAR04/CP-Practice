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
vector<vi > ans;
qi end0,end1;
//Main function
int main(){
    IOS;
    TIE;

    string str;
    cin>>str;

    int len=str.length();
    REP(i,len){
        if(str[i]==48){
            if(end1.E){
                end0.push(ans.size());
                ans.pb(vi{i});
            }
            else{
                ans[end1.front()].pb(i);
                end0.push(end1.front());
                end1.pop();
            }
        }
        else{
            if(end0.E){
                cout<<-1<<endl;
                return 0;
            }
            else{
                ans[end0.front()].pb(i);
                end1.push(end0.front());
                end0.pop();
            }
        }
    }

    if(end1.E){
        cout<<ans.size()<<endl;

        for(auto v : ans){
            cout<<v.size()<<" ";

            for(auto x : v)
                cout<<x+1<<" ";

            cout<<endl;
        }
    }
    else
        cout<<-1<<endl;

    return 0;
}
