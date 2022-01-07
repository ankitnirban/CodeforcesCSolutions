#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    map<int,int> m;
    vector<int> perm;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        perm.push_back(x);
        m[x]++;
    }
    multiset<int> a,b;
    int count=0;
    for(auto &x:m){
        if(x.second==1){
            if(count%2==0){
                a.insert(x.first);
            }
            else{
                b.insert(x.first);
            }
            x.second--;
            count++;
        }
    }
    bool possible=false;
    if((int)a.size()==(int)b.size()){
        possible=true;
    }
    if((int)a.size()<(int)b.size()){
        for(auto &x:m){
            if(x.second>2){
                possible=true;
                a.insert(x.first);
                for(int i=0;i<x.second-1;i++){
                    b.insert(x.first);
                }
                x.second=0;
                break;
            }
        }
    }
    else if((int)a.size()>(int)b.size()){
        for(auto &x:m){
            if(x.second>2){
                possible=true;
                b.insert(x.first);
                for(int i=0;i<x.second-1;i++){
                    a.insert(x.first);
                }
                x.second=0;
                break;
            }
        }
    }
    string ans;
    if(possible){
        cout<<"YES"<<endl;
        for(auto &x:m){
            for(int i=0;i<x.second;i++){
                a.insert(x.first);
            }
        }

        for(int i=0;i<n;i++){
            auto it = a.find(perm[i]);
            if(it!=a.end()){
                ans.push_back('A');
                a.erase(it);
            }
            else{
                auto it1=b.find(perm[i]);
                ans.push_back('B');
                b.erase(it1);
            }
        }
        cout<<ans<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}