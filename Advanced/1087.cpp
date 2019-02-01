#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=210;
const int INF=0x3fffffff;
vector<int>pre[maxn],tempPath,path;
int n,k,s,weight[maxn],d[maxn],cost[maxn][maxn],G[maxn][maxn];
int numPath=0,maxW=0;
bool vis[maxn]={false};
int maxAvg=0;
map<string,int> cityToindex;
map<int,string> indexTocity;
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(d[j]<min&&vis[j]==false){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
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
}
void DFS(int v){
	if(v==s){
		tempPath.push_back(v);
		numPath++;
		int tempW=0;
		for(int i=tempPath.size()-2;i>=0;i--){
			int id=tempPath[i];
			tempW+=weight[id];
		}
		int tempAvg=tempW/(tempPath.size()-1);
		if(tempW>maxW){
			maxW=tempW;
			maxAvg=tempAvg;
			path=tempPath;
		}else if(tempW==maxW&&tempAvg>maxAvg){
			maxAvg=tempAvg;
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
	string start,city1,city2;
	cin>>n>>k>>start;
	fill(G[0],G[0]+maxn*maxn,INF);
	cityToindex[start]=0;
	indexTocity[0]=start;
	for(int i=1;i<n;i++){
		cin>>city1>>weight[i];
		cityToindex[city1]=i;
		indexTocity[i]=city1;
	}	
	for(int i=0;i<k;i++){
		cin>>city1>>city2;
		int c1=cityToindex[city1],c2=cityToindex[city2];
		cin>>G[c1][c2];
		G[c2][c1]=G[c1][c2];
	}
	Dijkstra(0);
	int rom=cityToindex["ROM"];
	DFS(rom);
	cout<<numPath<<" "<<d[rom]<<" "<<maxW<<" "<<(int)maxAvg<<endl;
	for(int i=path.size()-1;i>=0;i--){
		cout<<indexTocity[path[i]];
		if(i>0) cout<<"->";
	}
}