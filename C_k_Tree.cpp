#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
signed main(){
    int n,k,d;
    cin>>n>>k>>d;
    vector<int> dp1(n+1,0);//all elements less than d.
    dp1[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<d;j++){
            if(i-j>=0){
                dp1[i]=(dp1[i]+dp1[i-j])%mod;
            }
        }
    }
    vector<int> dp2(n+1,0);//containing at least one >d element.
    for(int i=1;i<n+1;i++){
        for(int j=d;j<=min(k,n);j++){
            if(i-j>=0){
                dp2[i]=(dp2[i]+dp1[i-j])%mod;
            }
        }
        for(int j=1;j<=min(n,k);j++){
            if(i-j>=0){
                dp2[i]=(dp2[i]+dp2[i-j])%mod;
            }
        }
    }
    cout<<dp2[n]<<endl;
    return 0;
}