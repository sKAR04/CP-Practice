//Strike me down and I shall become stronger than you can possibly imagine

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=n+1;i<=20000;++i){
        int cnt=0;
        set<int> digits;
        int temp=i;
        while(temp){
            digits.insert(temp%10);
            temp/=10;
            ++cnt;
        }
        if(cnt==digits.size()){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
