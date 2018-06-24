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
string str[100010];
pair<pair<int,string>,int> query[100010];
string ans[100010];

struct TrieNode{
    TrieNode *alpha[26]={};
    bool isEnd=false;
};

TrieNode *head;

void trieInsert(string foo){
    TrieNode *cur=head;
    int len=foo.length();
    REP(i,len){
        if(!(cur->alpha[foo[i]-97]))
            cur->alpha[foo[i]-97]=new TrieNode;
        cur=cur->alpha[foo[i]-97];
    }

    cur->isEnd=true;
}

string trieQuery(string foo){
    TrieNode *cur=head;
    int len=foo.length();
    string ans="";
    REP(i,len)
        if(cur->alpha[foo[i]-97]){
            ans+=foo[i];
            cur=cur->alpha[foo[i]-97];
        }
        else
            break;

    while(!cur->isEnd)
        REP(i,26)
            if(cur->alpha[i]){
                ans+=(char)(i+97);
                cur=cur->alpha[i];
                break;
            }

    return ans;
}
//Main function
int main(){
    IOS;
    TIE;

    head=new TrieNode;

    int n;
    cin>>n;
    FOR(i,1,n+1)
        cin>>str[i];

    int q;
    cin>>q;
    REP(i,q){
        cin>>query[i].F.F>>query[i].F.S;
        query[i].S=i;
    }
    sort(query,query+q);

    int cur=1;
    REP(i,q){
        FOR(j,cur,query[i].F.F+1)
            trieInsert(str[j]);
        cur=query[i].F.F+1;
        ans[query[i].S]=trieQuery(query[i].F.S);
    }

    REP(i,q)
        cout<<ans[i]<<endl;

    return 0;
}
