#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;
    cin>>s;
    int n=(int)s.length();
    map<char,int> m1;
    for(int i=0;i<n;i++){
        m1[s[i]]++;
    }
    int best=INT_MIN;
    for(auto &x:m1){
        best=max(best,x.second);
    }
    map<string,int> m2;
    for(char i='a';i<='z';i++){
        for(char j='a';j<='z';j++){
            string temp;
            temp.push_back(i);
            temp.push_back(j);
            m2.insert(make_pair(temp,0));
        }
    }
    vector<vector<int> > count((int)26,vector<int>(n,0));
    for(int i=0;i<26;i++){
        if(s[0]=='a'+i) count[i][0]=1;
        for(int j=1;j<n;j++){
            count[i][j]=count[i][j-1];
            if(s[j]=='a'+i) count[i][j]++;
        }
    }
    cout<<endl;
    for(auto &x:m2){
        for(int i=0;i<n-1;i++){
            if(s[i]==x.first[0]){
                x.second+=(count[x.first[1]-'a'][n-1]-count[x.first[1]-'a'][i]);
            }
        }
    }
    for(auto &x:m2){
        best=max(best,x.second);
    }
    cout<<best<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}