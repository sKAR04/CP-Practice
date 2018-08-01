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
    Node *child[26]={};
};

Node *root;
bool isGood[26];
//Main function
int main(){
    IOS;
    TIE;
    root=new Node();

    string str;
    cin>>str;

    string good;
    cin>>good;
    REP(i,26)
        isGood[i]=good[i]-48;

    int k;
    cin>>k;

    int cnt=0;
    int len=str.length();
    REP(i,len){
        Node *cur=root;
        int badCnt=0;
        FOR(j,i,len){
            if(!isGood[str[j]-97])
                ++badCnt;
            if(badCnt>k)
                break;
            if(!cur->child[str[j]-97]){
                ++cnt;
                cur->child[str[j]-97]=new Node();
            }
            cur=cur->child[str[j]-97];
        }
    }
    cout<<cnt<<endl;

    return 0;
}
