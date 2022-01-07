#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int best=INT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double d=(a[j]-a[i])/(j-i);
            vector<double> b(n);
            b[i]=a[i];
            b[j]=a[j];
            for(int x=i-1;x>=0;x--){
                b[x]=b[x+1]-d;
            }
            for(int x=j+1;x<n;x++){
                b[x]=b[x-1]+d;
            }
            for(int x=i+1;x<j;x++){
                b[x]=b[x-1]+d;
            }
            int curr=0;
            for(int i=0;i<n;i++){
                double diff=a[i]-b[i];
                diff=abs(diff);
                if(diff>0.000000000001) curr++;
            }
            best=min(best,curr);
        }
    }
    cout<<best<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}