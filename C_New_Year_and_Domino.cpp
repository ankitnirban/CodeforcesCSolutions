#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(vector<vector<int> > &dp1, vector<vector<int> > &dp2){
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    a1--;
    a2--;
    a3--;
    a4--;
    int ans=dp1[a3][a4];
    if(a2-1>=0) ans+=dp1[a1][a2-1];
    ans-=dp1[a1][a4];
    if(a2-1>=0) ans-=dp1[a3][a2-1];
    ans+=dp2[a3][a4];
    if(a1-1>=0)ans+=dp2[a1-1][a2];
    ans-=dp2[a3][a2];
    if(a1-1>=0)ans-=dp2[a1-1][a4];
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int> > dp1(n,vector<int>(m,0));
    for(int i=1;i<n;i++){
        if(a[i][0]=='#'){
            dp1[i][0]=dp1[i-1][0];
        }
        else{
            if(a[i-1][0]=='.'){
                dp1[i][0]=dp1[i-1][0]+1;
            }
            else{
                dp1[i][0]=dp1[i-1][0];
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]=='#'){
                dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
            }
            else{
                if(a[i-1][j]=='.'){
                    dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1]+1;
                }
                else{
                    dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
                }
            }
        }
    }

    //dp2
    vector<vector<int> > dp2(n,vector<int>(m,0));
    for(int i=1;i<m;i++){
        if(a[0][i]=='#'){
            dp2[0][i]=dp2[0][i-1];
        }
        else{
            if(a[0][i-1]=='.'){
                dp2[0][i]=dp2[0][i-1]+1;
            }
            else{
                dp2[0][i]=dp2[0][i-1];
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]=='#'){
                dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
            }
            else{
                if(a[i][j-1]=='.'){
                    dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1]+1;
                }
                else{
                    dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
                }
            }
        }
    }
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        solve(dp1,dp2);
    }

    return 0;
}