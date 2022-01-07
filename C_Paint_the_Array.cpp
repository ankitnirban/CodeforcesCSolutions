#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int g1=0,g2=0;
    for(int i=0;i<n;i+=2){
        g1=__gcd(g1,a[i]);
    }
    for(int i=1;i<n;i+=2){
        g2=__gcd(g2,a[i]);
    }
    if(g1==1&&g2==1){
        cout<<0<<endl;
        return;
    }
    if(g1==1&&g2!=1){
        for(int i=0;i<n;i+=2){
            if(a[i]%g2==0){
                cout<<0<<endl;
                return;
            }
        }
        cout<<g2<<endl;
        return;
    }
    if(g1!=1&&g2==1){
        for(int i=1;i<n;i+=2){
            if(a[i]%g1==0){
                cout<<0<<endl;
                return;
            }
        }
        cout<<g1<<endl;
        return;
    }
    bool flag=false;
    for(int i=0;i<n;i+=2){
        if(a[i]%g2==0){
            flag=true;
            break;
        }
    }
    if(flag){
        bool flag1=false;
        for(int i=1;i<n;i+=2){
            if(a[i]%g1==0){
                cout<<0<<endl;
                return;
            }
        }
        cout<<g1<<endl;
        return;
    }
    else{
        cout<<g2<<endl;
        return;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}