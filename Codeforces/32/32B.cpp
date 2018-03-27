//Strike me down and I shall become stronger than you can possibly imagine

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string code;
    cin>>code;
    while(code.size()){
        if(code[0]=='.'){
            cout<<0;
            code.replace(0,1,"");
        }
        else if(code[0]=='-' && code[1]=='.'){
            cout<<1;
            code.replace(0,2,"");
        }
        else{
            cout<<2;
            code.replace(0,2,"");
        }
    }
    cout<<'\n';
    return 0;
}
