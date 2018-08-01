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
ll arr[100010],rep[100010],setSize[100010];
bool isBlocked[100010],color[100010],invert[100010];

ll gcd(ll a,ll b){
    if(b)
        return gcd(b,a%b);
    return a;
}

ll getRep(ll x){
    while(x!=rep[x])
        x=rep[x];
    return x;
}

bool isInverted(ll x){
    bool ret=false;
    while(rep[x]!=x){
        ret^=invert[x];
        x=rep[x];
    }
    return ret;
}

void solve(){
    ll n,m;
    cin>>n>>m;

    FOR(i,1,n+1){
        cin>>arr[i];
        rep[i]=i;
        setSize[i]=1;
    }

    while(m--){
        int t;
        cin>>t;

        if(t==1){
            ll x,c;
            cin>>x>>c;
            arr[x]=c;
        }
        else if(t==2){
            ll x,y;
            cin>>x>>y;

            ll repX=getRep(x),repY=getRep(y);
            bool invX=isInverted(x),invY=isInverted(y);
            if(repX!=repY){
                if(setSize[repX]>setSize[repY]){
                    if(!(color[x]^color[y]^invX^invY))
                        invert[repY]=true;
                    setSize[repX]+=setSize[repY];
                    rep[repY]=repX;
                    isBlocked[repX]|=isBlocked[repY];
                }
                else{
                    if(!(color[x]^color[y]^invX^invY))
                        invert[repX]=true;
                    setSize[repY]+=setSize[repX];
                    rep[repX]=repY;
                    isBlocked[repY]|=isBlocked[repX];
                }
            }
            else if(!(color[x]^color[y]^invX^invY))
                isBlocked[repX]=true;
        }
        else{
            ll x,y,v;
            cin>>x>>y>>v;
            ll repX=getRep(x),repY=getRep(y);
            bool invX=isInverted(x),invY=isInverted(y);

            if(repX!=repY || isBlocked[repX])
                cout<<0<<endl;
            else{
                if(color[x]^color[y]^invX^invY)
                    cout<<"-";
                 cout<<(arr[x]*v)/gcd(arr[x]*v,arr[y])<<"/"<<arr[y]/gcd(arr[x]*v,arr[y])<<endl;
            }
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;
/*
    int t;
    cin>>t;

    while(t--)
        solve();
*/
    solve();
    return 0;
}
