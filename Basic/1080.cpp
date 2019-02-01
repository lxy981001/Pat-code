#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    string id;
    int g,gm,gf,gp;
}stu[10010];
bool cmp(node a,node b){
    return a.g!=b.g?a.g>b.g:a.id<b.id;
}
int main(){
    int p,m,n;
    cin>>p>>m>>n;
    string s;
    int score,cnt=1;
    vector<node>v,ans;
    map<string,int>mp;
    for(int i=0;i<p;i++){
        cin>>s>>score;
        if(score>=200){
            stu[i].gp=score;
            stu[i].id=s;
            stu[i].g=0;
            stu[i].gm=-1;
            stu[i].gf=-1;
            v.push_back(stu[i]);
            mp[s]=cnt++;
        }
    }
    for(int i=0;i<m;i++){
        cin>>s>>score;
        if(mp[s]!=0) v[mp[s]-1].gm=score;
    }
    for(int i=0;i<n;i++){
        cin>>s>>score;
        if(mp[s]!=0){
            int t=mp[s]-1;
            v[t].g=v[t].gf=score;
            if(v[t].gm>v[t].gf) v[t].g=int(v[t].gm*0.4+v[t].gf*0.6+0.5);
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i].g>=60) ans.push_back(v[i]);
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].id<<" "<<ans[i].gp<<" "<<ans[i].gm<<" "<<ans[i].gf<<" "<<ans[i].g<<endl;
    }
    return 0;
}
