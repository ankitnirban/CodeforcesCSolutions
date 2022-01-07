#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,h;
    cin>>n>>h;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=h;
    int ans=h;
    while(l<=r){
        int mid=l+(r-l)/2;
        int total=0;
        for(int i=0;i<n-1;i++){
            total+=min(a[i+1]-a[i],mid);
        }
        total+=mid;
        if(total>=h){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}