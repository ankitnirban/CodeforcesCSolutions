#include <bits/stdc++.h>
using namespace std;
#define int long long
double ans=0;
void dfs(vector<vector<int> > &tree, vector<bool> &visited, int pos, double level, double prob){
    visited[pos]=true;
    int count=0;
    for(int i=0;i<tree[pos].size();i++){
        if(!visited[tree[pos][i]]){
            count++;
        }
    }
    if(count==0){
        ans=ans+level*prob;
        return;
    }
    double new_prob=((double)1/(double)count);
    for(int i=0;i<tree[pos].size();i++){
        if(!visited[tree[pos][i]]){
            dfs(tree,visited,tree[pos][i],level+1,prob*new_prob);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int> > tree(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<bool> visited(n,false);
    dfs(tree,visited,0,(double)0,(double)1);
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}