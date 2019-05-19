/*
######################################################
#    I don't know what I'm doing with my life O.O    #
######################################################
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
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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
const ll MAXN=1e6+10;
ll a,b,n,l,t,m;
bool flag;
ll bSearch(ll low,ll high){
    ll mid=(low+high)>>1;
    // db(mid);
    if(low<=high){
        ll start=a+(l-1LL)*b,finish=a+(mid-1LL)*b,num=mid-l+1LL;
        ll sum=((start+finish)*num)/2LL;
        if(sum<=m*t && finish<=t){
            flag=true;
            return bSearch(mid+1,high);
        }
        else
            return bSearch(low,mid-1LL);
    }
    else
        return mid;
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>a>>b>>n;

    ll ans;
    while(n--){
        flag=false;
        cin>>l>>t>>m;
        ans=bSearch(l,MAXN);
        if(flag)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}
