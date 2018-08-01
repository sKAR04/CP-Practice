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

    int n,k,p;
    cin>>n>>k>>p;

    vi even,odd;
    REP(i,n){
        int x;
        cin>>x;

        if(x & 1)
            odd.pb(x);
        else
            even.pb(x);
    }

    bool flag=true;
    int oddCnt=odd.size();
    if(oddCnt<k-p)
        flag=false;
    else if((oddCnt+p-k) & 1)
        flag=false;
    else if(n-oddCnt+(oddCnt+p-k)/2<p)
        flag=false;

    if(flag){
        cout<<"YES"<<endl;
        vector<vi> oddParts,evenParts;
        REP(i,k-p){
            vi cur;
            cur.pb(odd[i]);
            oddParts.pb(cur);
        }

        FOR(i,k-p,oddCnt){
            vi cur;
            cur.pb(odd[i++]);
            cur.pb(odd[i]);
            evenParts.pb(cur);
        }

        for(int e : even){
            vi cur;
            cur.pb(e);
            evenParts.pb(cur);
        }

        if(p){
            while(evenParts.size()!=p){
                vi cur=evenParts.back();
                evenParts.pop_back();

                for(int e : cur)
                    evenParts[0].pb(e);
            }
        }
        else{
            while(evenParts.size()){
                vi cur=evenParts.back();
                evenParts.pop_back();

                for(int e : cur)
                    oddParts[0].pb(e);
            }
        }


        for(vi v : oddParts){
            cout<<v.size()<<" ";
            for(int o : v)
                cout<<o<<" ";
            cout<<endl;
        }

        for(vi v : evenParts){
            cout<<v.size()<<" ";
            for(int e : v)
                cout<<e<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
