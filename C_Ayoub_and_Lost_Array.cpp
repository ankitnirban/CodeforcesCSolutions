#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
signed main(){
    int n,l,r;
    cin>>n>>l>>r;
    int temp=r-l+1;
    int count0=temp/3,count1=temp/3,count2=temp/3;
    if(temp%3==1){
        int temp1=l%3;
        if(temp1==0){
            count0++;
        }
        else if(temp1==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    else if(temp%3==2){
        int temp1=l%3;
        if(temp1==0){
            count0++;
            count1++;
        }
        else if(temp1==1){
            count1++;
            count2++;
        }
        else{
            count2++;
            count0++;
        }
    }
    vector<vector<int> > dp(3,vector<int> (n,0));
    dp[0][0]=count0;
    dp[1][0]=count1;
    dp[2][0]=count2;
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                //dp[j][i]+=(dp[j][i-1]*count0);
                dp[j][i]=(dp[j][i]+((dp[j][i-1]*count0)%mod))%mod;
                //dp[j][i]+=(dp[j+1][i-1]*count2);
                dp[j][i]=(dp[j][i]+((dp[j+1][i-1]*count2)%mod))%mod;
                //dp[j][i]+=(dp[j+2][i-1]*count1);
                dp[j][i]=(dp[j][i]+((dp[j+2][i-1]*count1)%mod))%mod;
            }
            else if(j==1){
                //dp[j][i]+=(dp[j-1][i-1]*count1);
                dp[j][i]=(dp[j][i]+((dp[j-1][i-1]*count1)%mod))%mod;
                //dp[j][i]+=(dp[j][i-1]*count0);
                dp[j][i]=(dp[j][i]+((dp[j][i-1]*count0)%mod))%mod;
                //dp[j][i]+=(dp[j+1][i-1]*count2);
                dp[j][i]=(dp[j][i]+((dp[j+1][i-1]*count2)%mod))%mod;
            }
            else{
                //dp[j][i]+=(dp[j-2][i-1]*count2);
                dp[j][i]=(dp[j][i]+((dp[j-2][i-1]*count2)%mod))%mod;
                //dp[j][i]+=(dp[j-1][i-1]*count1);
                dp[j][i]=(dp[j][i]+((dp[j-1][i-1]*count1)%mod))%mod;
                //dp[j][i]+=(dp[j][i-1]*count0);
                dp[j][i]=(dp[j][i]+((dp[j][i-1]*count0)%mod))%mod;
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}