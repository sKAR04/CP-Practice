#include <iostream>

using namespace std;

bool is_fib[1010];

void gen_fib(){
    is_fib[0]=true;
    is_fib[1]=true;
    int prev=0,prev_prev=1,cur=1;
    while(cur<1010){
        is_fib[cur]=true;
        prev_prev=prev;
        prev=cur;
        cur=prev+prev_prev;
    }
}

int main(){
    gen_fib();
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        if(is_fib[i])
            cout<<"O";
        else
            cout<<"o";
    cout<<'\n';
    return 0;
}
