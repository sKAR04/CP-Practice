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

//Declare all variables and methods needed between this comment and the next one(OCD lol)
class Ribbon{
    public :
    int cntLower[26]={0};
    int cntUpper[26]={0};

    string str;
    int len;

    void getCnt(){
        len=str.length();
        REP(i,len)
            if(str[i]>96)
                ++cntLower[str[i]-97];
            else
                ++cntUpper[str[i]-65];
    }

    int getMaxVal(int k){
        int maxVal=0;
        REP(i,26){
            int cur=cntLower[i];
            if(cur==len && k==1)
                --cur;
            else if(k<=len-cur)
                cur+=k;
            else
                cur=len;
            maxVal=max(maxVal,cur);

            cur=cntUpper[i];
            if(cur==len && k==1)
                --cur;
            else if(k<=len-cur)
                cur+=k;
            else
                cur=len;
            maxVal=max(maxVal,cur);
        }

        return maxVal;
    }
};

//Main function
int main(){
    IOS;
    TIE;

    ll k;
    cin>>k;

    Ribbon kuro,shiro,katie;
    cin>>kuro.str>>shiro.str>>katie.str;

    kuro.getCnt();
    shiro.getCnt();
    katie.getCnt();

    int max0=kuro.getMaxVal(k);
    int max1=shiro.getMaxVal(k);
    int max2=katie.getMaxVal(k);

    if(max0>max1 && max0>max2)
        cout<<"Kuro"<<endl;
    else if(max1>max0 && max1>max2)
        cout<<"Shiro"<<endl;
    else if(max2>max0 && max2>max1)
        cout<<"Katie"<<endl;
    else
        cout<<"Draw"<<endl;

    return 0;
}
