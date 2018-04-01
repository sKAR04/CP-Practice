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
char grid[20][20];
int n,m;

bool isValid(int x,int y){
    if(x && x<n+1 && y && y<m+1)
        return true;
    return false;
}

vii genPairs(int x,int y){
    return vii{mp(x+1,y),mp(x-1,y),mp(x,y+1),mp(x,y-1)};
}

int eatPigMothaFucka(int x,int y){
    if(grid[x][y]=='W'){
        vii temp=genPairs(x,y);
        vii pigs;

        for(pi p : temp)
            if(isValid(p.F,p.S) && grid[p.F][p.S]=='P')
                pigs.pb(p);

        if(pigs.E){
            grid[x][y]='.';
            return 0;
        }
        else if(pigs.size()==1){
            grid[x][y]=grid[pigs[0].F][pigs[0].S]='.';
            return 1;
        }
        else{
            for(pi p : pigs){
                bool flag=true;
                vii temp=genPairs(p.F,p.S);
                vii wolves;

                for(pi p1 : temp)
                    if(isValid(p1.F,p1.S) && grid[p1.F][p1.S]=='W' && (p1.F!=x || p1.S!=y))
                        wolves.pb(p1);

                for(pi p1 : wolves){
                    vii temp1=genPairs(p1.F,p1.S);

                    int cnt=0;
                    for(pi p2 : temp1)
                        if(isValid(p2.F,p2.S) && grid[p2.F][p2.S]=='P')
                            ++cnt;

                    if(cnt==1){
                        flag=false;
                        break;
                    }
                }

                if(flag){
                    grid[x][y]=grid[p.F][p.S]='.';
                    return 1;
                }
            }

            grid[x][y]='.';
            return 0;
        }
    }
    else
        return 0;
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>m;

    FOR(i,1,n+1)
        FOR(j,1,m+1)
            cin>>grid[i][j];

    int cnt=0;
    FOR(i,1,n+1)
        FOR(j,1,m+1)
            cnt+=eatPigMothaFucka(i,j);

    cout<<cnt<<endl;

    return 0;
}
