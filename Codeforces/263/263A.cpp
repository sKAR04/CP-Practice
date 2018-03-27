//Strike me down and I shall become stronger than you can possibly imagine

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j){
            int temp;
            cin>>temp;
            if(temp)
                cout<<abs(2-i)+abs(2-j)<<'\n';
        }
    return 0;
}
