#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >G;
vector<bool>visit;
int cnt=0;
void DFS(int index){
	cnt++;
	visit[index]=true;
	for(int i=0;i<G[index].size();i++){
		if(visit[G[index][i]]==false) DFS(G[index][i]);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	G.resize(n+1);
	visit.resize(n+1);
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int even=0;
	for(int i=1;i<=n;i++){
		if(i!=1) cout<<" ";
		cout<<G[i].size();
		if(G[i].size()%2==0) even++;
	}
	cout<<endl;
	DFS(1);
	if(cnt==n&&even==n) cout<<"Eulerian";
	else if(cnt==n&&even==n-2)cout<<"Semi-Eulerian";
	else cout<<"Non-Eulerian";
	return 0;
}