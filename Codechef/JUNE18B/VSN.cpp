//Strike me down and I shall become stronger, than you can possibly imagine

#include <bits/stdc++.h>
using namespace std;

//Optimizations
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//save time
#define endl '\n'
#define db(x) cout << "> " << #x << ": " << x << endl;
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f

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

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Variables and Functions required
struct Vect{
    double i,j,k;
};

double SQUARE(double x){
    return x*x;
}

void solve(){
    Vect P,Q,C,D;
    double r;

    cin>>P.i>>P.j>>P.k;
    cin>>Q.i>>Q.j>>Q.k;
    cin>>D.i>>D.j>>D.k;
    cin>>C.i>>C.j>>C.k;
    cin>>r;

    Q.i-=P.i;
    Q.j-=P.j;
    Q.k-=P.k;

    C.i-=P.i;
    C.j-=P.j;
    C.k-=P.k;

    double A=(SQUARE(C.i)+SQUARE(C.j)+SQUARE(C.k)-SQUARE(r))*(SQUARE(D.i)+SQUARE(D.j)+SQUARE(D.k))-SQUARE((D.i*C.i+D.j*C.j+D.k*C.k));
    double B=2.0*((SQUARE(C.i)+SQUARE(C.j)+SQUARE(C.k)-SQUARE(r))*(Q.i*D.i+Q.j*D.j+Q.k*D.k)-(D.i*C.i+D.j*C.j+D.k*C.k)*(Q.i*C.i+Q.j*C.j+Q.k*C.k));
    double F=(SQUARE(C.i)+SQUARE(C.j)+SQUARE(C.k)-SQUARE(r))*(SQUARE(Q.i)+SQUARE(Q.j)+SQUARE(Q.k))-SQUARE(Q.i*C.i+Q.j*C.j+Q.k*C.k);
    
    double t;
    if(abs(A)<EPS)
        t=(-F/B);
    else
        t=(sqrt(SQUARE(B)-4*A*F)-B)/(2.0*A);
    cout<<setprecision(20)<<t<<endl;
}
//Main function
int main(){
    IOS;
    TIE;

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
