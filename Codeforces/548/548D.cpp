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
#define vii vector<pair<int,int>>
#define vlll vector<pair<ll,ll>>
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
int ans[200010],arr[200010],l[200010],r[200010];
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;
    FOR(i,1,n+1)
        cin>>arr[i];

    stack<int> s1;
    FOR(i,1,n+1){
        while(!s1.E && arr[s1.top()]>=arr[i])
            s1.pop();

        if(s1.E)
            l[i]=0;
        else
            l[i]=s1.top();
        s1.push(i);
    }

    stack<int> s2;
    DFOR(i,n,1){
        while(!s2.E && arr[s2.top()]>arr[i])
            s2.pop();

        if(s2.E)
            r[i]=n+1;
        else
            r[i]=s2.top();
        s2.push(i);
    }

    FOR(i,1,n+1)
        ans[r[i]-l[i]-1]=max(ans[r[i]-l[i]-1],arr[i]);
    DFOR(i,n,1)
        ans[i]=max(ans[i],ans[i+1]);

    FOR(i,1,n+1)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
