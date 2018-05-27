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

//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    int arr[n];
    set<int> s;
    REP(i,n){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    sort(arr,arr+n);

    vi ans;
    if(n==1){
        cout<<-1<<endl;
        return 0;
    }
    else if(s.size()==1)
        ans.pb(arr[0]);
    else if(n==2){
        ans.pb(2*arr[0]-arr[1]);
        ans.pb(2*arr[1]-arr[0]);
        if((arr[1]-arr[0])%2==0)
            ans.pb(arr[0]+(arr[1]-arr[0])/2);
    }
    else{
        map<int,int> diffCnt;
        FOR(i,1,n)
            ++diffCnt[arr[i]-arr[i-1]];

        if(diffCnt.size()>2);
        else if(diffCnt.size()==1){
            ans.pb(2*arr[0]-arr[1]);
            ans.pb(arr[n-1]+arr[1]-arr[0]);
        }
        else{
            if(n==3){
                if(2*(arr[1]-arr[0])==arr[2]-arr[1])
                    ans.pb(arr[1]+arr[1]-arr[0]);
                else if(2*(arr[2]-arr[1])==arr[1]-arr[0])
                    ans.pb(arr[1]-arr[2]+arr[1]);
            }
            else{
                int minDiff=INT_MIN,maxDiff=INT_MIN;
                for(auto it=diffCnt.begin();it!=diffCnt.end();++it)
                    if(it->S==n-2)
                        maxDiff=it->F;
                    else if(it->S==1)
                        minDiff=it->F;

                if(minDiff!=INT_MIN && maxDiff!=INT_MIN && minDiff==maxDiff*2)
                    FOR(i,1,n)
                        if(arr[i]-arr[i-1]==minDiff){
                            ans.pb(arr[i-1]+maxDiff);
                            break;
                        }
            }
        }
    }
    cout<<ans.size()<<endl;
    sort(all(ans));
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
