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
int n;
int getMinSwaps(string str,string valid){
    int ans=0;

    int pos=n;
    DFOR(i,n-1,0)
        if(str[i]==valid[1]){
            pos=i;
            break;
        }

    FOR(i,pos+1,n){
        char temp=str[i];
        str[i]=str[i-1];
        str[i-1]=temp;
        ++ans;
    }

    pos=n;
    DFOR(i,n-2,0)
        if(str[i]==valid[0]){
            pos=i;
            break;
        }

    FOR(i,pos+1,n-1){
        char temp=str[i];
        str[i]=str[i-1];
        str[i-1]=temp;
        ++ans;
    }

    REP(i,n)
        if(str[i]!=48){
            pos=i;
            break;
        }

    DFOR(i,pos,1){
        char temp=str[i];
        str[i]=str[i-1];
        str[i-1]=temp;
        ++ans;
    }

    if(str[n-2]==valid[0] && str[n-1]==valid[1])
        return ans;
    else
        return INF;
}
//Main function
int main(){
    IOS;
    TIE;

    string str;
    cin>>str;

    n=str.length();
    int ans=INF;

    if(n==1 && str[0]==48)
        ans=0;
    else if(n!=1){
        ans=min(ans,getMinSwaps(str,"00"));
        ans=min(ans,getMinSwaps(str,"25"));
        ans=min(ans,getMinSwaps(str,"50"));
        ans=min(ans,getMinSwaps(str,"75"));
    }

    if(ans==INF)
        ans=-1;
    cout<<ans<<endl;

    return 0;
}
