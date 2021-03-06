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

//Main function
int main(){
    IOS;
    TIE;

    string str0,str1;
    cin>>str0>>str1;

    if(str0.size()!=str1.size())
        cout<<"NO"<<endl;
    else if(str0.size()==1)
        if(str0[0]==str1[0])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    else if(str0==str1)
        cout<<"YES"<<endl;
    else{
        int idx1=-1,idx2=-1,idx3=-1;

        REP(i,str0.size())
            if(str0[i]!=str1[i])
                if(idx1==-1)
                    idx1=i;
                else if(idx2==-1)
                    idx2=i;
                else{
                    idx3=i;
                    break;
                }

        if(idx3!=-1)
            cout<<"NO"<<endl;
        else{
            char temp=str0[idx1];
            str0[idx1]=str0[idx2];
            str0[idx2]=temp;
            if(str0==str1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}
