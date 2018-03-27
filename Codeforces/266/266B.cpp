//Strike me down and I shall become stronger than you can possibly imagine

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,t;
    cin>>n>>t;
    string q;
    cin>>q;
    while(t--)
        for(int i=0;i<n-1;++i){
            if(q[i]=='B' && q[i+1]=='G'){
                q[i]='G';
                q[i+1]='B';
                ++i;
            }
        }
    cout<<q<<'\n';
    return 0;
}
