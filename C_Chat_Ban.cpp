#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int k,x;
    cin>>k>>x;
    if(x<=(k*(k+1))/2){
        int l=1,r=k;
        int ans=k;
        while(l<=r){
            int mid=l+(r-l)/2;
            int temp=(mid*(mid+1))/2;
            if(x<=temp){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    else if(x>(k*(k+1))/2&&x<=k*k){
        x-=((k*(k+1))/2);
        int l=1,r=k-1;
        int ans=k-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int temp=(k*(k-1))/2-((k-mid)*(k-mid-1))/2;
            if(x<=temp){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans+k<<endl;
    }
    else{
        cout<<2*k-1<<endl;
        return;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}