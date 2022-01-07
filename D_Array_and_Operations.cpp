#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    sort(a.begin(),a.end(),greater<int> ());
    int ans=0;
    int x=0,y=k;
    for(int i=0;i<k;i++){
        ans+=(a[y]/a[x]);
        x++;
        y++;
    }
    for(int i=2*k;i<n;i++){
        ans+=a[i];
    }
    cout<<ans<<endl;
}   
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}