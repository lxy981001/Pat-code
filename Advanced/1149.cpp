#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n,m,k,u,v;
    cin>>n>>m;
    map<int,vector<int> >mp;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    while(m--){
        cin>>k;
        vector<int>vi(k);
        int a[100000]={0};
        int flag=0;
        for(int i=0;i<k;i++){
            cin>>vi[i];
            a[vi[i]]=1;
        }   
        for(int i=0;i<vi.size();i++){
            for(int j=0;j<mp[vi[i]].size();j++){
                if(a[mp[vi[i]][j]]==1)flag=1;
            }
        }
        cout<<(flag?"No":"Yes")<<endl;
    }
    return 0;
}