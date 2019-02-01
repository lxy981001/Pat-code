#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int G[300][300];
int main(){
	int nv,ne,m,k;
	cin>>nv>>ne;
	for(int i=0;i<ne;i++){
		int u,v;
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>k;
		vector<int>v(k);
		int hash[300]={0},isClique=1,isMaximal=1;
		for(int j=0;j<k;j++){
			cin>>v[j];
			hash[v[j]]=1;
		}
		for(int j=0;j<k;j++){//判断是不是Clique
			if(isClique==0) break;
			for(int l=j+1;l<k;l++){
				if(G[v[j]][v[l]]==0){
					isClique=0;
					cout<<"Not a Clique"<<endl;
					break;
				}
			}
		}
		if(isClique==0) continue;
		for(int j=1;j<=nv;j++){//判断是不是maximal
			if(hash[j]==0){//遍历不在团里的点
				for(int l=0;l<k;l++){
					if(G[v[l]][j]==0)break;
					if(l==k-1) isMaximal=0;
				}
			}
			if(isMaximal==0){
				cout<<"Not Maximal"<<endl;
				break;
			}
		}
		if(isMaximal==1)cout<<"Yes"<<endl;
	}
	return 0;
}