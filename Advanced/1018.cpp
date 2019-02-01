#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
vector<int > pre[maxn],tempPath,path;
bool vis[maxn]={false};
int Cmax,n,sp,m,weight[maxn],G[maxn][maxn];
int d[maxn],numPath=0,minNeed=INF,minRemain=INF;
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,min=INF;
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1)return ;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=G[u][v]+d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v==0){
		tempPath.push_back(v);
		int need=0,remain=0;
		for(int i=tempPath.size()-1;i>=0;i--){
			int id=tempPath[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else{
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				}else{
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			path=tempPath;
		}else if(need==minNeed&&remain<minRemain){
			minRemain=remain;
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
	cin>>Cmax>>n>>sp>>m;
	int u,v;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=n;i++){
		cin>>weight[i];
		weight[i]-=Cmax/2;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v;
		cin>>G[u][v];
		G[v][u]=G[u][v];
	}
	Dijkstra(0);
	DFS(sp);
	cout<<minNeed<<" ";
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i];
		if(i>0) cout<<"->";
	}
	cout<<" "<<minRemain;
	return 0;
}