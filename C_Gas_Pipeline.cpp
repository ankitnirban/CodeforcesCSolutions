#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int total=n*a+(n+1)*b;
    int count=0;
    vector<int> seg;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            count++;
        }
        else{
            if(count>0) seg.push_back(count);
            count=0;
        }
    }
    if(count>0) seg.push_back(count);
    if((int)seg.size()==1){
        cout<<total<<endl;
        return;
    }
    total+=2*a;
    for(int i=1;i<(int)seg.size()-1;i++){
        if(seg[i]==1){
            total+=b;
            continue;
        }
        int temp1=seg[i]*b;
        int temp2=2*a+b;
        total+=min(temp1,temp2);
    }
    vector<int> seg1;
    int count1=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') count1++;
        else{
            if(count1>0){
                seg1.push_back(count1);
                count1=0;
            }
            else{
                continue;
            }
        }
    }
    total+=b;
    for(int i=0;i<(int)seg1.size();i++){
        total+=seg1[i]*b;
    }
    cout<<total<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}