#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<pair<int,int> > a(n-1);
    for(int i=0;i<n-1;i++){
        cin>>a[i].first>>a[i].second;
    }
    map<int,int> m;
    for(int i=0;i<n-1;i++){
        m[a[i].first]++;
        m[a[i].second]++;
    }
    int best=-1;
    for(auto &x:m){
        if(x.second>=3){
            best=x.first;
            break;
        }
    }
    vector<int> ans(n-1,-1);
    int f=0;
    for(int i=0;i<n-1;i++){
        if(a[i].first==best||a[i].second==best){
            ans[i]=f;
            f++;
        }
    }
    for(int i=0;i<n-1;i++){
        if(ans[i]==-1){
            ans[i]=f;
            f++;
        }
    }
    for(int i=0;i<n-1;i++) cout<<ans[i]<<endl;
    return 0;
}