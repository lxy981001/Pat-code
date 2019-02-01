#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
struct node {
	int v;
	int dis;
	node(int _v,int _dis) :v(_v),dis(_dis) {}
};
vector<node>Adj[maxn];
int n,m,st,ed;
int d[maxn],weight[maxn],w[maxn],num[maxn];
set<int >pre[maxn];
void bellmanFord(int s){
	fill(d,d+maxn,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	w[s]=weight[s];
	d[s]=0;
	num[s]=1;
	for(int i=0;i<n-1;i++){
		for(int u=0;i<n;u++){
			for(int j=0;j<Adj[u].size();j++){
				int v=Adj[u][j].v;
				int dis=Adj[u][j].dis;
				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					w[v]=w[u]+weight[v];
					num[v]=num[u];
					pre[v].clear();
					pre[v].insert(u);
				}else if(d[u]+dis==d[v]){
					if(w[u]+weight[v]>w[v]){
						w[v]=w[u]+weight[v];
					}
					pre[v].insert(u);
					num[v]=0;
					set<int>::iterator it;
					for( it=pre[v].begin();it!=pre[v].end();it++){
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
	bellmanFord(st);
	cout<<num[ed]<<" "<<w[ed];

	return 0;
}