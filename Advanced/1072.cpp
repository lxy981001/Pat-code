#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1020;
const int INF=0x3fffffff;
int n,m,k,ds,G[maxn][maxn];
int d[maxn];
bool vis[maxn]={false};
void Djikstra(int s){
	fill(d,d+maxn,INF);
	memset(vis,false,sizeof(vis));
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,min=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
				}	
			}
		}
	}
}
int getID(char str[]){
	int i=0,len=strlen(str),ID=0;
	while(i<len){
		if(str[i]!='G'){
			ID=ID*10+(str[i]-'0');
		}
		i++;
	}
	if(str[0]=='G') return n+ID;
	else return ID;
}
int main(){
	cin>>n>>m>>k>>ds;
	int u,v,w;
	char city1[5],city2[5];
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		cin>>city1>>city2>>w;
		u=getID(city1);
		v=getID(city2);
		G[v][u]=G[u][v];
	}
	double ansDis=-1,ansAvg=INF;
	int ansID=-1;
	for(int i=n+1;i<=n+m;i++){
		double minDis=INF,avg=0;
		Djikstra(i);
		for(int j=1;j<=n;j++){
			if(d[j]>ds){
				minDis=-1;
				break;
			}
			if(d[j]<minDis){
				minDis=d[j];
			}
			avg+=1.0*d[j]/n;
		}
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansID=i;
			ansDis=minDis;
			ansAvg=avg;
		}else if(minDis==ansDis&&avg<ansAvg){
			ansID=i;
			ansAvg=avg;
		}
	}
	if(ansID==-1) cout<<"No Solution"<<endl;
	else{
		printf("G%d\n",ansID-n );
		printf("%.1f %.1f\n",ansDis,ansAvg );
	}
	return 0;
}