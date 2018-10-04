//Strike me down and I shall become stronger, than you can possibly imagine

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
#define pf push_front

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Variables and Functions required
inline void solve(){
    int n;
    cin>>n;

    int arr[1<<n];
    REP(i,(1<<n))
        cin>>arr[i];
    sort(arr,arr+(1<<n));

    map<int,bool> exists;
    vi elements;

    FOR(i,1,(1<<n)){
        int cur=arr[i];
        if(exists.find(cur)!=exists.end())
            continue;
        else{
            for(int e : elements)
                exists[cur+e]=true;

            vi temp;
            for(auto it=exists.begin();it!=exists.end();++it)
                temp.pb(cur+it->F);
            for(int t : temp)
                exists[t]=true;

            elements.pb(cur);
        }
    }

    for(int e : elements)
        cout<<e<<" ";
    cout<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
