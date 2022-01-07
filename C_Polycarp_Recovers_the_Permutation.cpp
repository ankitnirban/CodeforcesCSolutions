#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<1<<" "<<2<<endl;
        return;
    }
    if(a[0]!=n&&a[n-1]!=n){
        cout<<-1<<endl;
        return;
    }
    deque<int> ans;
    int x=0,y=n-1;
    while(x<y){
        if(a[x]<a[y]){
            ans.push_front(a[x]);
            x++;
        }
        else{
            ans.push_back(a[y]);
            y--;
        }
    }
        if(a[0]==n){
            ans.push_front(n);
        }
        else{
            ans.push_back(n);
        }
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop_front();
        }
        cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}