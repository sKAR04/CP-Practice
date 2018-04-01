/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

//save time
#define endl '\n'
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

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

//Input methods
template <typename T>
void getFoo(T &x){
    x=0;
    register char c=gc();
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
}

template <typename T1,typename T2>
void getFoo(T1 &x,T2 &y){
    getFoo(x);
    getFoo(y);
}

template <typename T1,typename T2,typename T3>
void getFoo(T1 &x,T2 &y,T3 &z){
    getFoo(x);
    getFoo(y);
    getFoo(z);
}
//Declare all variables and methods needed between this comment and the next one(OCD lol)
vll luckyNums;
void convertToNum(string str){
    ll x=0;

    int len=str.length();
    REP(i,len)
        x=x*10+(str[i]-48);

    luckyNums.pb(x);
}

void genLuckyNums(string str){
    if(str.size()>11)
        return ;
    else{
        convertToNum(str+"4");
        genLuckyNums(str+"4");

        convertToNum(str+"7");
        genLuckyNums(str+"7");
    }
}

int binarySearch(int low,int high,ll key){
    int mid=(low+high) >> 1;

    if(low<=high)
        if(luckyNums[mid]>key)
            return binarySearch(low,mid-1,key);
        else if(luckyNums[mid]==key)
            return mid;
        else
            return binarySearch(mid+1,high,key);
    else
        return mid;
}

//Main function
int main(){
    IOS;
    TIE;
    ll l,r;
    cin>>l>>r;

    genLuckyNums("");

    sort(all(luckyNums));

    ll ans=0;

    int idx;
    if(l<=4LL)
        idx=0;
    else{
        idx=binarySearch(0,luckyNums.size()-1,l);
        if(luckyNums[idx]<l)
            ++idx;
    }

    ll prevVal=l;
    while(luckyNums[idx]<r){
        ans+=(luckyNums[idx]-prevVal+1)*luckyNums[idx];
        prevVal=luckyNums[idx]+1;
        ++idx;
    }
    ans+=(r-prevVal+1)*luckyNums[idx];

    cout<<ans<<endl;

    return 0;
}
