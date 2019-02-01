#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
vector<int> pre[maxn],tempPath,path;
int G[maxn][maxn],d[maxn],cost[maxn][maxn],mincost=INF;
bool vis[maxn]={false};
int n,m,st,ed;
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return ;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}else if(d[u]+G[u][v]==d[v]){
				pre[v].push_back(u);
			}
		}
	}
}
void DFS(int v){
	if(v==st){
		tempPath.push_back(v);
		int tempCost=0;
		for(int i=tempPath.size()-1;i>0;i--){
			int id=tempPath[i],idnext=tempPath[i-1];
			tempCost+=cost[id][idnext];
		}
		if(tempCost<mincost){
			mincost=tempCost;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main(){
	cin>>n>>m>>st>>ed;
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		cin>>G[u][v]>>cost[u][v];
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];
	}	
	Dijkstra(st);
	DFS(ed);
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
	cout<<d[ed]<<" "<<mincost;
	return 0;
}