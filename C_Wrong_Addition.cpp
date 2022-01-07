#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    int a=n,s=m;
    cin>>a>>s;
    vector<int> aa;
    while(a){
        aa.push_back(a%10);
        a/=10;
    }
    reverse(aa.begin(),aa.end());
    vector<int> ss;
    while(s){
        ss.push_back(s%10);
        s/=10;
    }
    reverse(ss.begin(),ss.end());
    if(aa.size()==ss.size()){
        cout<<m-n<<endl;
        return;
    }
    while()
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}