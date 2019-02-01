#include<iostream>
#include<vector>
using namespace std;
const int inf=0x3fffffff;
int e[510][510],w[510][510],dis[510],Time[510],weight[510],pre[510];
vector<int> dispath,temppath,timepath,timepre[510];
bool visit[510];
int n,m,sou,des,v1,v2,one_way,length,t;
void dfs_dis(int x){
	dispath.push_back(x);
	if (x==sou)return;
	dfs_dis(pre[x]);
}
int minnode=inf;
void dfs_time(int x){
	temppath.push_back(x);
	if (x==sou){
		if (temppath.size()<minnode){
			minnode=temppath.size();
			timepath=temppath;
		}
		temppath.pop_back();
		return;
	}
	for (int i=0;i<timepre[x].size();i++)
		dfs_time(timepre[x][i]);
	temppath.pop_back();
}
void dijkstra_dis(int s){
	dis[s]=0;
	weight[s]=0;
	for (int i=0;i<n;i++)
		pre[i]=i;
	for (int i=0;i<n;i++){
		int u=-1,MIN=inf;
		for (int j=0;j<n;j++){
			if (visit[j]==false&&dis[j]<MIN){
				MIN=dis[j];
				u=j;
			}
		}
		if (u==-1)break;
		visit[u]=true;
		for (int v=0;v<n;v++){
			if (visit[v]==false&&e[u][v]!=inf){
				if (e[u][v]+dis[u]<dis[v]){
					dis[v]=e[u][v]+dis[u];
					weight[v]=weight[u]+w[u][v];
					pre[v]=u;
				}else if(dis[v]==e[u][v]+dis[u]&&weight[u]+w[u][v]<weight[v]){
					weight[v]=weight[u]+w[u][v];
					pre[v]=u;
				}
			}
		}
	}
}
void dijkstra_time(int s){
	Time[s]=0;
	for (int i=0;i<n;i++){
		int u=-1,MIN=inf;
		for (int j=0;j<n;j++){
			if (visit[j]==false&&MIN>Time[j]){
				MIN=Time[j];
				u=j;
			}
		}
		if (u==-1)break;
		visit[u]=true;
		for (int v=0;v<n;v++){
			if (visit[v]==false&&w[u][v]!=inf){
				if (w[u][v]+Time[u]<Time[v]){
					Time[v]=w[u][v]+Time[u];
					timepre[v].clear();
					timepre[v].push_back(u);
				}else if (Time[v]==w[u][v]+Time[u])
					timepre[v].push_back(u);
			}
		}
	}
}
int main(){
	fill(visit,visit+510,false);
	fill(e[0],e[0]+510*510,inf);
	fill(w[0],w[0]+510*510,inf);
	fill(weight,weight+510,inf);
	fill(dis,dis+510,inf);
	fill(Time,Time+510,inf);
	cin>>n>>m;
	for (int i=0;i<m;i++){
		scanf("%d %d %d %d %d",&v1,&v2,&one_way,&length,&t);
		if (one_way!=1){
			e[v1][v2]=e[v2][v1]=length;
			w[v1][v2]=w[v2][v1]=t;
		}else if (one_way==1){
			e[v1][v2]=length;
			w[v1][v2]=t;
		}
	}
	cin>>sou>>des;
	dijkstra_dis(sou);
	dfs_dis(des);
	fill(visit,visit+510,false);
	dijkstra_time(sou);
	dfs_time(des);
	printf("Distance = %d",dis[des]);
	if (timepath==dispath){
		printf("; Time = %d: ",Time[des]);
		for (int i=timepath.size()-1;i>=0;i--){
			cout<<timepath[i];
			if (i!=0)cout<<" -> ";
		}
	}else{
		printf(": ");
		for (int i=dispath.size()-1;i>=0;i--){
			cout<<dispath[i];
			if (i!=0)cout<<" -> ";
		}
		cout<<endl;
		printf("Time = %d: ",Time[des]);
		for (int i=timepath.size()-1;i>=0;i--){
			cout<<timepath[i];
			if (i!=0)cout<<" -> ";
		}
	}
	return 0;
}
