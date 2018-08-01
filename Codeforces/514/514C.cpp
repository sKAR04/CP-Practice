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
struct Node{
    Node *child[3]={};
    bool isEnd=false;
};

Node *Trie;
bool exists;
string str;

void insertNode(){
    int len=str.length();
    Node *cur=Trie;
    REP(i,len){
        if(!cur->child[str[i]-97])
            cur->child[str[i]-97]=new Node;
        cur=cur->child[str[i]-97];
    }
    cur->isEnd=true;
}

void findString(Node *cur,int idx,bool flag){
    if(exists)
        return ;

    if(idx!=str.length()){
        if(!flag){
            REP(i,3)
                if(cur->child[i]){
                    if(str[idx]-97==i)
                        findString(cur->child[i],idx+1,false);
                    else
                        findString(cur->child[i],idx+1,true);
                }
        }
        else if(cur->child[str[idx]-97])
            findString(cur->child[str[idx]-97],idx+1,true);
    }
    else if(cur->isEnd)
        exists=flag;
}
//Main function
int main(){
    IOS;
    TIE;

    int n,m;
    cin>>n>>m;

    Trie=new Node;
    REP(i,n){
        cin>>str;
        insertNode();
    }

    REP(i,m){
        cin>>str;

        exists=false;
        findString(Trie,0,false);

        if(exists)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
