//Strike me down and I shall become stronger than you can possibly imagine

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int x=0,y=0,z=0;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        x-=a;
        y-=b;
        z-=c;
    }
    if(!x && !y && !z)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
