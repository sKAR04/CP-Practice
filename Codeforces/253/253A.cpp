
//Strike me down and I shall become stronger, than you can possibly imagine

#include <bits/stdc++.h>
#include <fstream>
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

//general
#define E empty()

//Variables and Functions required

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n,m;
    fin>>n>>m;
    if(n>=m){
        REP(i,m)
            fout<<"BG";
        REP(i,n-m)
            fout<<"B";
    }
    else{
        REP(i,n)
            fout<<"GB";
        REP(i,m-n)
            fout<<"G";
    }
    fout<<endl;
    return 0;
}
