#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    pair<int,int> x=make_pair(-100000,100000);
    pair<int,int> y=make_pair(-100000,100000);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        int p,q,r,s;
        cin>>p>>q>>r>>s;
        if(p==0){
            x.first=max(x.first,a);
        }
        if(q==0){
            y.second=min(y.second,b);
        }
        if(r==0){
            x.second=min(x.second,a);
        }
        if(s==0){
            y.first=max(y.first,b);
        }
    }
    if(x.first>x.second||y.first>y.second){
        cout<<0<<endl;
    }
    else{
        cout<<1<<" ";
        cout<<x.first<<" "<<y.first<<endl;
    }
}
signed main(){
    int tc;
    cin>>tc;
    while(tc--) solve();
    return 0;
}