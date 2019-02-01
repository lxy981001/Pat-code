#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node{
	string id;
	int Gp,Gm,Gf,G;
} stu[10010];
bool cmp(node a,node b){
	return a.G!=b.G?a.G>b.G:a.id<b.id;
}
int main(){
	int p,m,n,score;
	string s;
	cin>>p>>m>>n;
	vector<node>v,ans;
	map<string,int>mp;
	int cnt=1;
	for(int i=0;i<p;i++){
		cin>>s>>score;
		if(score>=200){
			// stu[i].id=s;
			// stu[i].Gp=score;
			// stu[i].G=0;
			// stu[i].Gf=-1;
			// stu[i].Gm=-1;
			mp[s]=cnt++;
			v.push_back(node{s,score,-1,-1,0});
		}
	}
	for(int i=0;i<m;i++){
		cin>>s>>score;
		if(mp[s]!=0) v[mp[s]-1].Gm=score;
	}
	for(int i=0;i<n;i++){
		cin>>s>>score;
		if(mp[s]!=0){
			int temp=mp[s]-1;
			v[temp].Gf=v[temp].G=score;
			if(v[temp].Gm>v[temp].Gf) v[temp].G=int(v[temp].Gm*0.4+v[temp].Gf*0.6+0.5);
		}
	}
	for(int i=0;i<v.size();i++){
		if(v[i].G>=60) ans.push_back(v[i]);
	}	
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].id<<" "<<ans[i].Gp<<" "<<ans[i].Gm<<" "<<ans[i].Gf<<" "<<ans[i].G<<endl;
	}
	return 0;
}