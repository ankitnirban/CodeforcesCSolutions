#include <bits/stdc++.h>
using namespace std;
#define int long long
void sieve(vector<bool> &isPrime){
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<1000001;i++){
        if(isPrime[i]){
            for(int j=i*i;j<1000001;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
void solve(vector<bool> &isPrime){
    int n,e;
    cin>>n>>e;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        if(isPrime[a[i]]){
            int x=0;
            int y=0;
            for(int j=i-e;j>=0;j-=e){
                if(a[j]==1){
                    x++;
                }
                else break;
            }
            for(int j=i+e;j<n;j+=e){
                if(a[j]==1){
                    y++;
                }
                else break;
            }
            ans+=(x*(y+1)+y);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<bool> isPrime(1000001,true);
    sieve(isPrime);
    int t=1;
    cin>>t;
    while(t--) solve(isPrime);
    return 0;
}