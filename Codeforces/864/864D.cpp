
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
int cnt[200010];
vi rep;
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    REP(i,n){
        cin>>arr[i];
        ++cnt[arr[i]];
    }
    int minCnt=0;
    queue<int> toInsert;
    FOR(i,1,n+1)
        if(!cnt[i]){
            ++minCnt;
            toInsert.push(i);
        }
    cout<<minCnt<<endl;
    REP(i,n){
        if(toInsert.E)
            break;
        int cur=toInsert.front();
        if(cnt[arr[i]]==-1){
            arr[i]=cur;
            toInsert.pop();
        }
        else if(cnt[arr[i]]!=1){
            if(cur>arr[i])
                cnt[arr[i]]=-1;
            else{
                --cnt[arr[i]];
                arr[i]=cur;
                toInsert.pop();
            }
        }
    }
    REP(i,n)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
