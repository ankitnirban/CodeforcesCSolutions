#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    vector<int> a(A);
    int x=0,y=*max_element(a.begin(),a.end());
    int ans=-1;
    while(x<=y){
        a=A;
        int mid=x+(y-x)/2;
        bool possible=true;
        for(int i=n-1;i>=2;i--){
            if(mid>a[i]){
                possible=false;
                break;
            }
            else{
                int temp=min(a[i]-mid,A[i]);
                temp/=3;
                a[i-1]+=temp;
                a[i-2]+=(2*temp);
                a[i]-=(3*temp);
            }
        }
        if(a[0]<mid||a[1]<mid) possible=false;
        if(possible){
            ans=mid;
            x=mid+1;
        }
        else{
            y=mid-1;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}