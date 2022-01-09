#include <bits/stdc++.h>
using namespace std;
//#define int long long
signed main(){
    int temp=1e7+1;
    vector<int> a(temp,0);
    int n;
    //cin>>n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    vector<bool> sieve(temp,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i<temp;i++){
        if(sieve[i]){
            for(long long j=(long long)i*i;j<temp;j+=(long long)i){
                sieve[j]=false;
            }
        }
    }
    vector<int> primes;
    for(int i=0;i<temp;i++){
        if(sieve[i]) primes.push_back(i);
    }
    vector<int> f(temp,0);
    /*for(int i=2;i<temp;i++){
        if(sieve[i]){
            for(int j=i;j<temp;j+=i){
                f[i]+=a[j];
            }
        }
    }*/
    for(int i=0;i<(int)primes.size();i++){
        for(int j=primes[i];j<temp;j+=primes[i]){
            f[primes[i]]+=a[j];
        }
    }
    for(int i=1;i<(int)f.size();i++){
        f[i]+=f[i-1];
    }
    int q;
    //cin>>q;
    scanf("%d", &q);
    while(q--){
        int l,r;
        scanf("%d", &l);
        scanf("%d", &r);
        //int ans=f[r]-f[l-1];
        int ans=f[min(temp-1,r)]-f[min(l-1,temp-1)];
        printf("%d\n", ans);
    }
    return 0;
}