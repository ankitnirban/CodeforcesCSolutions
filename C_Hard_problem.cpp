#include <bits/stdc++.h>
using namespace std;
#define int long long
bool lexSmaller(string &a, string &b){
    int index=-1;
    for(int i=0;i<a.length()&&i<b.length();i++){
        if(a[i]!=b[i]){
            index=i;
            break;
        }
    }
    if(index==-1){
        if(a.length()>b.length()) return false;
        else return true;
    }
    else{
        if(a[index]<b[index]) return true;
        else return false;
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(auto &x:c) cin>>x;
    vector<string> a(n);
    for(auto &x:a) cin>>x;
    int temp=1e14+1;
    vector<vector<int> > dp(n,vector<int> (2,temp));//dp[i][j]=min cost to achieve order upto index. j={0,1}
    dp[0][0]=0;
    dp[0][1]=c[0];
    for(int i=1;i<n;i++){
        string p=a[i-1];
        string q=a[i];
        string pp=a[i-1];
        string qq=a[i];
        reverse(pp.begin(),pp.end());
        reverse(qq.begin(),qq.end());
        if(dp[i-1][0]==temp&&dp[i-1][1]==temp){
            dp[i][0]=temp;
            dp[i][1]=temp;
        }   
        else if(dp[i-1][0]!=temp&&dp[i-1][1]!=temp){
            if(lexSmaller(p,q)){
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
            }
            if(lexSmaller(pp,q)){
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
            }
            if(lexSmaller(p,qq)){
                dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
            }
            if(lexSmaller(pp,qq)){
                dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
            }
        }
        else if(dp[i-1][0]==temp&&dp[i-1][1]!=temp){
            if(lexSmaller(pp,q)){
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
            }
            if(lexSmaller(pp,qq)){
                dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
            }
        }
        else{
            if(lexSmaller(p,q)){
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
            }
            if(lexSmaller(p,qq)){
                dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
            }
        }
    }
    int ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==temp) cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}