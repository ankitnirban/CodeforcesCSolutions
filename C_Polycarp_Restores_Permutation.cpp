#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++) cin>>a[i];
    for(int i=1;i<n-1;i++) a[i]+=a[i-1];
    int temp=*min_element(a.begin(),a.end());
    int first=-1;
    if(temp<0){
        first=1-temp;
    }
    else{
        first=1;
    }
    vector<int> ans;
    ans.push_back(first);
    for(int i=0;i<n-1;i++){
        ans.push_back(first+a[i]);
    }
    set<int> st;
    for(int i=0;i<n;i++) st.insert(ans[i]);
    if((int)st.size()==n){
        for(auto x:st){
            if(x>n||x<1){
                cout<<-1<<endl;
                return 0;
            }
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}