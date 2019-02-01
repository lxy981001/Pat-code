#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
std::vector<int> G[maxn];
int father[maxn];
bool isRoot[maxn];
int findFather(int x){
	if(x==father[x]) return x;
	else{
		int F=findFather(father[x]);
		father[x]=F;
		return F;
	}
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB) father[faA]=faB;
}
void init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}
int calBlock(int n){
	int block=0;
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]=true;
	}
	for(int i=1;i<=n;i++){
		block+=isRoot[i];
	}
	return block;
}
int maxH=0;
vector<int >temp,ans;
void DFS(int u,int height,int pre){
	if(height>maxH){
		temp.clear();
		temp.push_back(u);
		maxH=height;
	}else if(maxH==height){
		temp.push_back(u);
	}
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]==pre) continue;
		DFS(G[u][i],height+1,u);
	}
}
int main(){
	int a,b,n;
	cin>>n;
	init(n);
	for(int i=1;i<n;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	int block=calBlock(n);
	if(block!=1){
		printf("Error: %d components\n",block );
	}else{
		DFS(1,1,-1);
		ans=temp;
		DFS(ans[0],1,-1);
		for(int i=0;i<temp.size();i++){
			ans.push_back(temp[i]);
		}
		sort(ans.begin(),ans.end());
		cout<<ans[0]<<endl;
		for(int i=1;i<ans.size();i++){
			if(ans[i]!=ans[i-1]){
				cout<<ans[i]<<endl;
			}
		}	
	}
	return 0;
}