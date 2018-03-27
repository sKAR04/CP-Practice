
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
int n,w,h;
int dp[5010],prevIdx[5010];
map<pi,int> envMap;
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>w>>h;
    pi env[n];
    REP(i,n){
        cin>>env[i].F>>env[i].S;
        envMap[env[i]]=i+1;
    }
    sort(env,env+n);
    int idx=n;
    REP(i,n)
        if(env[i].F>w && env[i].S>h){
            idx=i;
            break;
        }
    vii eff;
    FOR(i,idx,n)
        eff.pb(env[i]);
    n=eff.size();
    if(!n){
        cout<<0<<endl;
        return 0;
    }
    REP(i,n){
        if(eff[i].S<=h){
            prevIdx[i]=-1;
            dp[i]=INT_MIN;
            continue;
        }
        int maxVal=INT_MIN,maxIdx=-1;
        REP(j,i)
            if(maxVal<dp[j] && eff[j].S<eff[i].S && eff[j].F<eff[i].F){
                maxVal=dp[j];
                maxIdx=j;
            }
        if(maxVal!=INT_MIN){
            prevIdx[i]=maxIdx;
            dp[i]=maxVal+1;
        }
        else{
            prevIdx[i]=-1;
            dp[i]=1;
        }
    }
    int maxVal=0,maxIdx=0;
    REP(i,n)
        if(maxVal<dp[i]){
            maxVal=dp[i];
            maxIdx=i;
        }
    stack<int> ans;
    int curIdx=maxIdx;
    while(curIdx!=-1){
        ans.push(envMap[eff[curIdx]]);
        curIdx=prevIdx[curIdx];
    }
    cout<<ans.size()<<endl;
    while(!ans.E){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
    return 0;
}
