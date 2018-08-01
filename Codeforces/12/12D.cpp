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
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
ll segTree[1 << 21];
pair<ll,pll> chicks[500010];

void updateTree(ll low,ll high,ll pos,ll qPos,ll val){
    int mid=(low+high) >> 1;

    if(qPos<low || qPos>high)
        return ;
    else if(low==high)
        segTree[pos]=max(val,segTree[pos]);
    else{
        updateTree(low,mid,2*pos+1,qPos,val);
        updateTree(mid+1,high,2*pos+2,qPos,val);
        segTree[pos]=max(segTree[2*pos+1],segTree[2*pos+2]);
    }
}

ll queryTree(ll low,ll high,ll pos,ll qLow,ll qHigh){
    ll mid=(low+high) >> 1;

    if(qLow>high || qHigh<low)
        return 0LL;
    else if(qLow<=low && qHigh>=high)
        return segTree[pos];
    else
        return max(queryTree(low,mid,2*pos+1,qLow,qHigh),queryTree(mid+1,high,2*pos+2,qLow,qHigh));
}
//Main function
int main(){
    IOS;
    TIE;

    ll n;
    cin>>n;
    REP(i,n)
        cin>>chicks[i].F;
    REP(i,n)
        cin>>chicks[i].S.F;
    REP(i,n)
        cin>>chicks[i].S.S;
    sort(chicks,chicks+n);

    map<ll,ll> cntMap;
    REP(i,n)
        ++cntMap[chicks[i].S.F];

    ll curPos=0;
    for(auto it=cntMap.begin();it!=cntMap.end();++it){
        it->S+=curPos;
        curPos=it->S;
        --it->S;
    }

    ll dumbChicks=0LL;
    DFOR(i,n-1,0){
        ll cur=chicks[i].F;

        vector<pair<ll,pll>> equalChicks;
        while(i>=0 && chicks[i].F==cur)
            equalChicks.pb(chicks[i--]);

        for(auto chick : equalChicks)
            if(cntMap[chick.S.F]!=n-1){
                ll maxRichness=queryTree(0,n-1,0,cntMap[chick.S.F]+1,n-1);
                if(maxRichness>chick.S.S)
                    ++dumbChicks;
            }

        for(auto chick : equalChicks)
            updateTree(0,n-1,0,cntMap[chick.S.F],chick.S.S);
        ++i;
    }
    cout<<dumbChicks<<endl;

    return 0;
}
