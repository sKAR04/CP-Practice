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
inline void solve(){
    string str;
    cin>>str;
    map<char,queue<int> > charMap;
    int arr[26];
    fill(arr,arr+26,0);
    int len=str.length();
    FOR(i,1,len+1){
        ++arr[str[i-1]-97];
        charMap[str[i-1]].push(i);
    }
    if(len & 1){
        int oddChar=-1;
        bool flag=true;
        REP(i,26)
            if(arr[i] & 1){
                if(oddChar==-1)
                    oddChar=i;
                else{
                    flag=false;
                    break;
                }
            }
        if(flag){
            REP(i,26){
                int alphaCnt=charMap[97+i].size();
                alphaCnt/=2;
                REP(j,alphaCnt){
                    cout<<charMap[97+i].front()<<" ";
                    charMap[97+i].pop();
                }
            }
            cout<<charMap[oddChar+97].front()<<" ";
            charMap[97+oddChar].pop();
            DFOR(i,25,0){
                int alphaCnt=charMap[97+i].size();
                REP(j,alphaCnt){
                    cout<<charMap[97+i].front()<<" ";
                    charMap[97+i].pop();
                }
            }
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    else{
        bool flag=true;
        REP(i,26)
            if(arr[i] & 1){
                flag=false;
                break;
            }
        if(flag){
            REP(i,26){
                int alphaCnt=charMap[97+i].size();
                alphaCnt/=2;
                REP(j,alphaCnt){
                    cout<<charMap[97+i].front()<<" ";
                    charMap[97+i].pop();
                }
            }
            DFOR(i,25,0){
                int alphaCnt=charMap[97+i].size();
                REP(j,alphaCnt){
                    cout<<charMap[97+i].front()<<" ";
                    charMap[97+i].pop();
                }
            }
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
