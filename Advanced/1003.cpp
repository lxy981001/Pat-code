#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=0x3ffffff;
struct node{
	int v,dist;
	node(int _v,int _dist):v(_v),dist(_dist){}
};
vector<node>Adj[maxn];
int n,m,st,ed;
int G[maxn][maxn],weight[maxn];
int d[maxn],w[maxn],num[maxn];
set<int>pre[maxn];
void Bellman(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n-1;i++){
		for(int u=0;u<n;u++){
			for(int j=0;j<Adj[u].size();j++){
				int v=Adj[u][j].v;
				int dist=Adj[u][j].dist;
				if(d[u]+dist<d[v]){
					d[v]=d[u]+dist;
					w[v]=w[u]+weight[v];
					num[v]=num[u];
					pre[v].clear();
					pre[v].insert(u);
				}else if(d[u]+dist==d[v]){
					if(w[v]<w[u]+weight[v]){
						w[v]=w[u]+weight[v];
					}
					pre[v].insert(u);
					num[v]=0;
					for(auto it=pre[v].begin();it!=pre[v].end();it++){
						num[v]+=num[*it];
					}
				}
			}
		}	
	}
}
int main(){
	cin>>n>>m>>st>>ed;
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	int u,v,wt;
	for(int i=0;i<m;i++){
		cin>>u>>v>>wt;
		Adj[u].push_back(node(v,wt));
		Adj[v].push_back(node(u,wt));
	}
	Bellman(st);
	cout<<num[ed]<<" "<<w[ed]<<endl;
	return 0;
}