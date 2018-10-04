#include <bits/stdc++.h>

#define EPS  0.000000001
#define PI   3.141592653593

using namespace std;

typedef long long ll;

int dp[510][10010];

bool myCmp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
    if(p1.first.first<p2.first.first)
        return true;
    else if(p1.first.first==p2.first.first && p1.first.second>p2.first.second)
        return true;
    return false;
}

//Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,c;
    cin>>n>>c;

    vector<pair<pair<int,int>,int>> v(n+1);
    v[0]=make_pair(make_pair(0,0),0);
    for(int i=1;i<=n;++i){
        cin>>v[i].first.second>>v[i].first.first;
        v[i].second=i;
    }
    sort(v.begin()+1,v.end(),myCmp);

    for(int i=1;i<=n;++i){
        for(int j=0;j<=c;j++){
            dp[i][j]=dp[i-1][j];
            if(j+max(v[i].first.first,v[i].first.second)-v[i].first.first<=c && j-v[i].first.first>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i].first.first]+1);
        }
    }
/*
    for(int i=1;i<=n;++i){
        cout<<"Storage : "<<v[i].first.first<<" "<<" Download : "<<v[i].first.second<<endl;
        for(int j=0;j<=c;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
*/
    vector<int> ans;
    int curMax=0,curStorage=0;
    for(int i=0;i<=c;++i)
        if(curMax<dp[n][i]){
            curMax=dp[n][i];
            curStorage=i;
        }

    //cout<<curMax<<" "<<curStorage<<endl;
    for(int i=n;i>=1;--i)
        if(dp[i][curStorage]!=dp[i-1][curStorage] && curStorage){
            ans.push_back(v[i].second);
            curStorage-=v[i].first.first;
        }

    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;--i)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
