#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<vector<int> > temp(m);
    for(int i=0;i<n;i++){
        temp[i%m].push_back(a[i]);
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<temp[i].size();j++){
            temp[i][j]+=temp[i][j-1];
        }
    }

    vector<int> dp(n,0);
    dp[0]=a[0];
    for(int i=1;i<m;i++){
        dp[i]=dp[i-1]+a[i];
    }
    for(int i=m;i<n;i++){
        int q=i/m;
        int r=i%m;
        dp[i]=dp[i-1]+temp[r][q];
    }
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}