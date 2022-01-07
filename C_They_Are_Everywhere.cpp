#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<int> st;
    for(int i=0;i<n;i++) st.insert(s[i]);
    int total=st.size();
    map<char,int> m;
    int x=0,y=0;
    m[s[x]]++;
    int ans=n;
    while(y<n){
        if(m.size()==total){
            ans=min(ans,y-x+1);
            m[s[x]]--;
            if(m[s[x]]==0){
                m.erase(s[x]);
            }
            x++;
        }
        else{
            y++;
            m[s[y]]++;
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