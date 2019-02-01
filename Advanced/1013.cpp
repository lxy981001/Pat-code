#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
vector<int >G[maxn];
bool vis[maxn]={false};
int deletPoint;
void DFS(int v){
	if(v==deletPoint) return;
	vis[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(vis[G[v][i]]==false){
			DFS(G[v][i]);
		}
	}
}
int n,m,k;

int main(){

	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		//cin>>a>>b;
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<k;i++){
		//cin>>deletPoint;
		scanf("%d",&deletPoint);
		memset(vis,false,sizeof(vis));
		int block=0;
		for(int i=1;i<=n;i++){
			if(i!=deletPoint&&vis[i]==false){
				DFS(i);
				block++;
			}
		}
		//cout<<block-1<<endl;
		printf("%d\n",block-1 );
	}
	return 0;
}