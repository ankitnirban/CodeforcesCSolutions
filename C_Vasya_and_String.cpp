#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> a(n,0);
    vector<int> b(n,0);
    if(s[0]=='a') a[0]=1;
    else b[0]=1;
    for(int i=1;i<n;i++){
        if(s[i]=='a'){
            a[i]=a[i-1]+1;
            b[i]=b[i-1];
        }
        else{
            a[i]=a[i-1];
            b[i]=b[i-1]+1;
        }
    }
    int x=1,y=n;
    int ans=1;
    while(x<=y){
        int mid=x+(y-x)/2;
        bool possible=false;
        
        for(int i=0;i<=n-mid;i++){
            int temp1=0;
            int temp2=0;
            if(i==0){
                temp1=a[i+mid-1];
                temp2=b[i+mid-1];
            }
            else{
                temp1=a[i+mid-1]-a[i-1];
                temp2=b[i+mid-1]-b[i-1];
            }
            int temp=min(temp1,temp2);
            if(temp<=k){
                possible=true;
                break;
            }
            else{
                continue;
            }
        }
        if(possible){
            ans=mid;
            x=mid+1;
        }
        else{
            y=mid-1;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}