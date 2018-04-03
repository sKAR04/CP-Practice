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

    int n,m;
    cin>>n>>m;

    int color[n+1];
    fill(color,color+n+1,0);

    while(m--){
        int x,y,z;
        cin>>x>>y>>z;

        if(!color[x] && !color[y] && !color[z]){
            color[x]=1;
            color[y]=2;
            color[z]=3;
        }
        else if(!color[x] && !color[y]){
            color[y]=color[z]%3+1;
            color[x]=color[y]%3+1;
        }
        else if(!color[x] && !color[z]){
            color[x]=color[y]%3+1;
            color[z]=color[x]%3+1;
        }
        else if(!color[y] && !color[z]){
            color[y]=color[x]%3+1;
            color[z]=color[y]%3+1;
        }
        else if(!color[x])
            color[x]=6-(color[y]+color[z]);
        else if(!color[y])
            color[y]=6-(color[x]+color[z]);
        else if(!color[z])
            color[z]=6-(color[x]+color[y]);
    }

    FOR(i,1,n+1)
        if(!color[i])
            cout<<1<<" ";
        else
            cout<<color[i]<<" ";
    cout<<endl;
    
    return 0;
}
