#include <bits/stdc++.h>
using namespace std;
#define int long long
bool dfs(vector<vector<int> > &graph, vector<int> &color, int pos, string &ans){
    color[pos]=1;
    for(int i=0;i<(int)graph[pos].size();i++){
        if(color[graph[pos][i]]==0){
            bool flag=dfs(graph,color,graph[pos][i],ans);
            if(flag){
                return true;
            }
        }
        else if(color[graph[pos][i]]==1){
            return true;
        }
        else{
            continue;
        }
    }
    color[pos]=2;
    ans.push_back((char)('a'+pos));
    return false;
}
signed main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int> > graph(26);
    vector<int> color(26,0);
    for(int i=0;i<n-1;i++){
        string p=a[i];
        string q=a[i+1];
        int index=-1;
        for(int j=0;j<(int)p.length()&&j<(int)q.length();j++){
            if(p[j]!=q[j]){
                index=j;
                break;
            }
        }
        if(index==-1){
            if((int)p.length()>(int)q.length()){
                cout<<"Impossible"<<endl;
                return 0;
            }
            else{
                continue;
            }
        }
        graph[p[index]-'a'].push_back(q[index]-'a');
    }
    string ans;
    for(int i=0;i<26;i++){
        if(color[i]==0&&!graph[i].empty()){
            bool cyclic=dfs(graph,color,i,ans);
            if(cyclic){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(char c='a';c<='z';c++){
        if(find(ans.begin(),ans.end(),c)==ans.end()){
            cout<<c;
        }
    }
    cout<<ans<<endl;
    return 0;
}