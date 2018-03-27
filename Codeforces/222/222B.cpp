
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
int table[1010][1010];
int row[1010],col[1010];
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    REP(i,1010)
        row[i]=col[i]=i;
    int n,m,k;
    cin>>n>>m>>k;
    FOR(i,1,n+1)
        FOR(j,1,m+1)
            cin>>table[i][j];
    while(k--){
        int temp;
        char type;
        int x,y;
        cin>>type>>x>>y;
        if(type=='g')
            cout<<table[row[x]][col[y]]<<endl;
        else if(type=='c'){
            temp=col[x];
            col[x]=col[y];
            col[y]=temp;
        }
        else{
            temp=row[x];
            row[x]=row[y];
            row[y]=temp;
        }
    }
    return 0;
}
