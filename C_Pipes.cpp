#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int count=0;
    for(int i=0;i<n;i++){
        if(count%2==0){
            if(a[i]!='1'&&a[i]!='2'){
                if(b[i]=='1'||b[i]=='2'){
                    cout<<"NO"<<endl;
                    return;
                }
                else{
                    count++;
                }
            }
        }
        else{
            if(b[i]!='1'&&b[i]!='2'){
                if(a[i]=='1'||a[i]=='2'){
                    cout<<"NO"<<endl;
                    return;
                }
                else{
                    count++;
                }
            }
        }
    }
    if(count%2==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}