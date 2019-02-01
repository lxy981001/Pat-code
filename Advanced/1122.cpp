#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
	int n,m,G[210][210]={0},cnt;
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
	}
	cin>>cnt;
	int k;
	while(cnt--){
		cin>>k;
		vector<int>v(k);
		int flag1=1,flag2=1;
		set<int>ans;
		for(int i=0;i<k;i++){
			cin>>v[i];
			ans.insert(v[i]);
		}
		if(ans.size()!=n||k-1!=n||v[0]!=v[k-1]) flag1=0;
		for(int i=0;i<k-1;i++){
			if(G[v[i]][v[i+1]]==0) flag2=0;
		}	
		if(flag1&&flag2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}