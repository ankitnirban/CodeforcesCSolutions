#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    sum*=2;
    if(sum%n!=0){
        cout<<0<<endl;
        return;
    }
    sum/=n;
    sort(a.begin(),a.end());
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    int ans=0;
    for(auto x:m){
        int r=sum-x.first;
        if(r>=x.first){
            if(r==x.first){
                ans+=(x.second*(x.second-1))/2;
            }
            else{
                if(m.find(r)!=m.end()){
                    ans+=x.second*m[r];
                }
                else{
                    ans+=0;
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}