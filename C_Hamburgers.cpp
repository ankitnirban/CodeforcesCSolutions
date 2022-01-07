#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;
    cin>>s;
    int ra=0,rb=0,rc=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B') ra++;
        else if(s[i]=='S') rb++;
        else rc++;
    }
    int na,nb,nc;
    cin>>na>>nb>>nc;
    int pa,pb,pc;
    cin>>pa>>pb>>pc;
    int money;
    cin>>money;
    int x=0,y=max(max(na,nb),nc)+money;
    int ans=0;
    while(x<=y){
        int mid=x+(y-x)/2;
        int tempa=mid*ra;
        int tempb=mid*rb;
        int tempc=mid*rc;
        int cost=0;
        if(tempa>na){
            cost+=((tempa-na)*pa);
        }
        if(tempb>nb){
            cost+=((tempb-nb)*pb);
        }
        if(tempc>nc){
            cost+=((tempc-nc)*pc);
        }
        if(cost<=money){
            ans=mid;
            x=mid+1;
        }
        else{
            y=mid-1;
        }
    }
    cout<<endl;
    cout<<ans<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}