//Strike me down, and I shall become stronger than you can possibly imagine
//Streak Count : 0

#include <iostream>
using namespace std;
int main(){
    string str1,str2;
    cin>>str1>>str2;
    string ans="";
    int len=str1.length();
    for(int i=0;i<len;++i)
        if(str1[i]==str2[i])
            ans+="0";
        else
            ans+="1";
    cout<<ans<<endl;
    return 0;
}
