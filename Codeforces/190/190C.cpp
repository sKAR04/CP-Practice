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
vector<string> v;
string ans="";
int getType(int idx){
    if(idx==v.size())
        return idx;

    if(v[idx]=="int")
        ans+="int";
    else{
        ans+="pair<";
        idx=getType(idx+1);
        ans+=",";
        idx=getType(idx)-1;
        ans+=">";
    }
    return idx+1;
}
//Main function
int main(){
    IOS;
    TIE;

    int n;
    cin>>n;

    string str;
    while(cin>>str)
        v.pb(str);

    bool flag=false;
    int cnt=0,idx=-1;
    REP(i,v.size())
        if(cnt>0){
            idx=i;
            break;
        }
        else if(v[i]=="int")
            ++cnt;
        else
            --cnt;

    if(idx!=-1 || cnt!=1)
        flag=true;

    getType(0);
    if(flag)
        cout<<"Error occurred";
    else
        cout<<ans;
    cout<<endl;

    return 0;
}
