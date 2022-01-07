#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> temp2;//dene wale
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            temp2.push_back(i+1);
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=0;i<n;i++) s.erase(a[i]);
    vector<int> temp1(s.begin(),s.end());//lene wale
    if(!temp1.empty()){
        if((int)temp1.size()%2==1){
            if(temp1[0]==temp2[0]){
                swap(temp2[0],temp2[1]);
            }
            a[temp2[0]-1]=temp1[0];
        }
        int start=0;
        if((int)temp1.size()%2==1) start++;
        for(int i=start;i<(int)temp1.size();i+=2){
            if(temp1[i]==temp2[i]||temp1[i+1]==temp2[i+1]){
                a[temp2[i]-1]=temp1[i+1];
                a[temp2[i+1]-1]=temp1[i];
            }
            else{
                a[temp2[i]-1]=temp1[i];
                a[temp2[i+1]-1]=temp1[i+1];
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}