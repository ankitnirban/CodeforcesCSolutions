#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> temp1,temp2;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=0;i<n;i++){
        if(a[i]>n){
            temp1.push_back(a[i]);
        }
        else{
            if(s.find(a[i])==s.end()){
                temp1.push_back(a[i]);
            }
            else{
                s.erase(a[i]);
            }
        }
    }
    for(auto &x:s){
        temp2.push_back(x);
    }
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    for(int i=0;i<(int)temp1.size();i++){
        int temp=temp1[i]/2;
        if(temp1[i]%2==0) temp--;
        if(temp2[i]>temp){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<(int)temp1.size()<<endl;
}
signed main(){
    int tc;
    cin>>tc;
    while(tc--) solve();
    return 0;
}