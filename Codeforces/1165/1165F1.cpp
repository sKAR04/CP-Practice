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
const int MAXN=1e5+10;
vii sale;
int k[MAXN],n,m,tot;
int bSearch(int low,int high){
    int mid=(low+high)>>1;
    if(low<=high){
        int last[n+1]={};
        for(auto s : sale)
            if(s.F<=mid)
                last[s.S]=max(s.F,last[s.S]);

        vii v;
        FOR(i,1,n+1)
            v.pb(mp(last[i],i));
        sort(all(v));

        int cnt=0,sum=0,tmp;
        auto it=v.begin();
        FOR(i,1,mid+1){
            ++cnt;
            while(it!=v.end() && it->F<i)
                ++it;

            while(it!=v.end() && it->F==i){
                tmp=min(cnt,k[it->S]);
                cnt-=tmp;
                sum+=tmp;
                ++it;
            }
        }

        sum=(tot-sum)*2;
        if(sum<=cnt)
            return bSearch(low,mid-1);
        else
            return bSearch(mid+1,high);
    }
    else
        return mid+1;
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;

    FOR(i,1,n+1){
        cin>>k[i];
        tot+=k[i];
    }

    int d,t;
    REP(i,m){
        cin>>d>>t;
        sale.pb(mp(d,t));
    }

    cout<<bSearch(1,int(2e5+10))<<endl;

    return 0;
}
