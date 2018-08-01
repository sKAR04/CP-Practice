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

    int n;
    cin>>n;

    vi arr(n);
    int sum=0;
    vi rem[3];
    REP(i,n){
        cin>>arr[i];
        sum+=arr[i];
        rem[arr[i]%3].pb(arr[i]);
    }
    sort(all(arr),greater<int>());
    sort(all(rem[0]));
    sort(all(rem[1]));
    sort(all(rem[2]));

    if(arr[n-1])
        cout<<-1<<endl;
    else{
        if(sum%3==1){
            if(rem[1].size())
                arr.erase(find(all(arr),rem[1][0]));
            else if(rem[2].size()>1){
                arr.erase(find(all(arr),rem[2][0]));
                arr.erase(find(all(arr),rem[2][1]));
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }
        else if(sum%3==2){
            if(rem[2].size())
                arr.erase(find(all(arr),rem[2][0]));
            else if(rem[1].size()>1){
                arr.erase(find(all(arr),rem[1][0]));
                arr.erase(find(all(arr),rem[1][1]));
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }

        sort(all(arr),greater<int>());
        if(!arr[0])
            cout<<0<<endl;
        else{
            for(int x : arr)
                cout<<x;
            cout<<endl;
        }
    }

    return 0;
}
