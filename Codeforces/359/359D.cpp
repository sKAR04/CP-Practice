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
ll sparseGcd[300010][20],sparseMin[300010][20];
ll arr[300010];
ll n,ans;

ll gcd(ll a,ll b){
    if(!b)
        return a;
    return gcd(b,a%b);
}

void genTables(){
    REP(i,n)
        sparseGcd[i][0]=sparseMin[i][0]=arr[i];

    ll logN;
    REP(i,32)
        if(n&(1LL<<i))
            logN=i+1;

    FOR(j,1,logN+1)
        REP(i,n){
            ll l=i,r=i+(1LL<<j)-1;
            if(r<=n-1){
                sparseGcd[i][j]=gcd(sparseGcd[i][j-1],sparseGcd[r-(1LL<<(j-1))+1][j-1]);
                sparseMin[i][j]=min(sparseMin[i][j-1],sparseMin[r-(1LL<<(j-1))+1][j-1]);
            }
            else{
                r=n-1;
                ll len=r-l+1;
                ll logLen;
                REP(i,32)
                    if(len&(1<<i))
                        logLen=i;

                sparseGcd[i][j]=gcd(sparseGcd[i][logLen],sparseGcd[r-(1LL<<logLen)+1][logLen]);
                sparseMin[i][j]=min(sparseMin[i][logLen],sparseMin[r-(1LL<<logLen)+1][logLen]);
            }
        }
}

void binarySearch(ll low,ll high){
    ll mid=(low+high) >> 1;
    if(low<=high){
        ll logMid;
        REP(i,32)
            if(mid&(1LL<<i))
                logMid=i;

        bool flag=false;
        REP(i,n){
            ll l=i,r=i+mid-1;
            if(r>n-1)
                break;
            ll rangeGCD=gcd(sparseGcd[i][logMid],sparseGcd[r-(1LL<<logMid)+1][logMid]);
            ll rangeMIN=min(sparseMin[i][logMid],sparseMin[r-(1LL<<logMid)+1][logMid]);

            if(rangeMIN==rangeGCD){
                /*
                db(mid);
                db(logMid);
                db(i);
                db(rangeGCD);
                cout<<endl;
                */
                flag=true;
                break;
            }
        }

        if(flag){
            ans=max(ans,mid);
            binarySearch(mid+1,high);
        }
        else
            binarySearch(low,mid-1);
    }
}

//Main function
int main(){
    IOS;
    TIE;

    cin>>n;
    REP(i,n)
        cin>>arr[i];

    genTables();

    binarySearch(1LL,n);

    ll logAns;
    REP(i,32)
        if(ans&(1LL<<i))
            logAns=i;

    vll lVal;
    REP(i,n){
        ll l=i,r=i+ans-1;
        if(r>n-1)
            break;
        ll rangeGCD=gcd(sparseGcd[i][logAns],sparseGcd[r-(1LL<<logAns)+1][logAns]);
        ll rangeMIN=min(sparseMin[i][logAns],sparseMin[r-(1LL<<logAns)+1][logAns]);

        if(rangeMIN==rangeGCD)
            lVal.pb(i+1);
    }

    cout<<lVal.size()<<" "<<ans-1<<endl;
    for(ll x : lVal)
        cout<<x<<" ";
    cout<<endl;
    /*
    cout<<endl;
    REP(i,n){
        REP(j,4)
            cout<<sparseGcd[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    REP(i,n){
        REP(j,4)
            cout<<sparseMin[i][j]<<" ";
        cout<<endl;
    }
    */
    return 0;
}
