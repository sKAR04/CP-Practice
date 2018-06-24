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
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int dpLeft[3000010],dpRight[3000010];
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    string str;
    cin>>str;
    str="$"+str+"$";

    FOR(i,1,n+1)
        if(str[i]=='.')
            dpLeft[i]=dpLeft[i-1]+1;

    DFOR(i,n,1)
        if(str[i]=='.')
            dpRight[i]=dpRight[i+1]+1;

    int cur=0;
    FOR(i,1,n+1)
        if(dpLeft[i] && !dpLeft[i+1])
            cur+=(dpLeft[i]-1);

    while(m--){
        int idx;
        char c;
        cin>>idx>>c;

        if(str[idx]=='.' && c!='.'){
            cur-=(dpLeft[idx-1]+dpRight[idx+1]);
            cur+=(max(dpLeft[idx-1]-1,0)+max(dpRight[idx+1]-1,0));
            dpLeft[idx]=dpRight[idx]=0;
        }
        else if(str[idx]!='.' && c=='.'){
            cur-=(max(dpLeft[idx-1]-1,0)+max(dpRight[idx+1]-1,0));
            cur+=(dpLeft[idx-1]+dpRight[idx+1]);
            dpLeft[idx]=dpLeft[idx-1]+1;
            dpRight[idx]=dpRight[idx+1]+1;
        }
        str[idx]=c;
        
        cout<<cur<<endl;
    }

    return 0;
}
