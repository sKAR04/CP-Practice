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
int n,m;
string str;
char grid[60][60];
pi startPos,endPos;
char direc[]={'U','D','L','R'};

bool possible=false;

bool check(pi p){
    if(p.F>0 && p.F<=n && p.S>0 && p.S<=m && grid[p.F][p.S]!='#')
        return true;
    return false;
}

void dfs(pi cur,int cnt){
    pi nextDir[]={mp(cur.F+1,cur.S),mp(cur.F-1,cur.S),mp(cur.F,cur.S+1),mp(cur.F,cur.S-1)};
    char c=direc[str[cnt]-48];
    pi nextPair;
    if(c=='U')
        nextPair=nextDir[0];
    else if(c=='D')
        nextPair=nextDir[1];
    else if(c=='R')
        nextPair=nextDir[2];
    else
        nextPair=nextDir[3];
    if(cur==endPos){
        possible=true;
        return ;
    }
    if(!check(nextPair))
        return ;
    if(cnt==str.length())
        return ;
    dfs(nextPair,cnt+1);
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sort(direc,direc+4);
    cin>>n>>m;
    FOR(i,1,n+1)
        FOR(j,1,m+1){
            cin>>grid[i][j];
            if(grid[i][j]=='S')
                startPos=mp(i,j);
            else if(grid[i][j]=='E')
                endPos=mp(i,j);
        }
    cin>>str;
    int cnt=0;
    do {
        dfs(startPos,0);
        if(possible)
            ++cnt;
        possible=false;
    }while(std::next_permutation(direc,direc+4));
    cout<<cnt<<endl;
    return 0;
}
