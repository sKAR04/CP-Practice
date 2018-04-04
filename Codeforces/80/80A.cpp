/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <iostream>
#include <cstring>

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

//Declare all variables and methods needed between this comment and the next one(OCD lol)
bool isPrime[110];

void sieve(){
    memset(isPrime,true,sizeof(isPrime));

    isPrime[0]=isPrime[1]=false;
    
    REP(i,110)
        if(isPrime[i])
            for(int j=2*i;j<110;j+=i)
                isPrime[j]=false;
}
//Main function
int main(){
    IOS;
    TIE;

    sieve();

    int x,y;
    cin>>x>>y;

    if(!isPrime[y]){
        cout<<"NO"<<endl;
        return 0;
    }

    FOR(i,x+1,y)
        if(isPrime[i]){
            cout<<"NO"<<endl;
            return 0;
        }

    cout<<"YES"<<endl;

    return 0;
}
