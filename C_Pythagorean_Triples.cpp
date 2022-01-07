#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    if(n==1||n==2){
        cout<<-1<<endl;
        return 0;
    }

    if(n%2==0){
        int a=(n*n)/4+1;
        int b=(n*n)/4-1;
        cout<<a<<" "<<b<<endl;
    }
    else{
        int a=(n*n+1)/2;
        int b=(n*n-1)/2;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}