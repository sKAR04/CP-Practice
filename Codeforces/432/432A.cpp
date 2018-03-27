//Strike me down and I shall become stronger than you can possibly imagine

#include <bits/stdc++.h>

using namespace std;

int cnt[6];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    while(n--){
        int temp;
        cin>>temp;
        ++cnt[temp];
    }
    int ans=0;
    for(int i=0;i<=5-k;++i)
        ans+=cnt[i];
    cout<<ans/3<<'\n';
    return 0;
}
