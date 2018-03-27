
//Strike me down and I shall become stronger, than you can possibly imagine

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
char cake[11][11];
bool marked[11][11];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin>>r>>c;
    FOR(i,1,r+1)
        FOR(j,1,c+1)
            cin>>cake[i][j];
    FOR(i,1,r+1){
        bool canEat=true;
        FOR(j,1,c+1)
            if(cake[i][j]=='S'){
                canEat=false;
                break;
            }
        if(canEat){
            FOR(j,1,c+1)
                marked[i][j]=true;
        }
    }
    FOR(j,1,c+1){
        bool canEat=true;
        FOR(i,1,r+1)
            if(cake[i][j]=='S'){
                canEat=false;
                break;
            }
        if(canEat){
            FOR(i,1,r+1)
                marked[i][j]=true;
        }
    }
    int cnt=0;
    FOR(i,1,r+1)
        FOR(j,1,c+1)
            if(marked[i][j])
                ++cnt;
    cout<<cnt<<endl;
    return 0;
}
