//Strike me down and I shall become stronger, than you can possibly imagine
//Streak Count : 1

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
int toPalindrome(string str){
    int cnt=0,n=str.length();
    REP(i,n/2)
        cnt+=min(abs(str[i]-str[n-i-1]),26-abs(str[i]-str[n-i-1]));
    return cnt;
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,p;
    cin>>n>>p;
    string str;
    cin>>str;
    --n;
    --p;
    int ans=toPalindrome(str);
    int leftCnt=0,rightCnt=0;
    if(n & 1){
        if(p<=(n-1)/2){
            REP(i,p)
                if(str[i]!=str[n-i]){
                    leftCnt=p-i;
                    break;
                }
            DFOR(i,(n-1)/2,p+1)
                if(str[i]!=str[n-i]){
                    rightCnt=i-p;
                    break;
                }
        }
        else{
            FOR(i,(n+1)/2,p)
                if(str[i]!=str[n-i]){
                    leftCnt=p-i;
                    break;
                }
            DFOR(i,n,p+1)
                if(str[i]!=str[n-i]){
                    rightCnt=i-p;
                    break;
                }
        }
    }
    else{
        if(p<=n/2){
            REP(i,p)
                if(str[i]!=str[n-i]){
                    leftCnt=p-i;
                    break;
                }
            DFOR(i,n/2,p+1)
                if(str[i]!=str[n-i]){
                    rightCnt=i-p;
                    break;
                }
        }
        else{
            FOR(i,n/2+1,p)
                if(str[i]!=str[n-i]){
                    leftCnt=p-i;
                    break;
                }
            DFOR(i,n,p+1)
                if(str[i]!=str[n-i]){
                    rightCnt=i-p;
                    break;
                }
        }
    }
    int temp1=min(leftCnt,rightCnt),temp2=max(rightCnt,leftCnt);
    ans+=(2*temp1+temp2);
    cout<<ans<<endl;
    return 0;
}
