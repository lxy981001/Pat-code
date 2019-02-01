#include<iostream>
#include<queue>
using namespace std;
struct node{
	int x,y,z;
} Node;
const int maxm=1300,maxn=130,maxl=70;
int m,n,l,t;
int X[6]={1,-1,0,0,0,0};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={0,0,0,0,1,-1};
int pixel[maxm][maxn][maxl];
bool inq[maxm][maxn][maxl]={false};
bool judge(int x,int y,int z){
	if(x>=m||x<0||y>=n||y<0||z>=l||z<0)return false;
	if(inq[x][y][z]==true||pixel[x][y][z]==0) return false;
	return true;
}
int BFS(int x,int y,int z){
	queue<node> q;
	int ans=0;
	Node.x=x,Node.y=y,Node.z=z;
	q.push(Node);
	inq[x][y][z]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		ans++;
		for(int i=0;i<6;i++){
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newz=top.z+Z[i];
			if(judge(newx,newy,newz)){
				Node.x=newx,Node.y=newy,Node.z=newz;
				q.push(Node);
				inq[newx][newy][newz]=true;
			}
		}
	}
	if(ans>=t) return ans;
	else return 0;
}
int main(){
	cin>>m>>n>>l>>t;
	for(int z=0;z<l;z++){
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				cin>>pixel[x][y][z];
			}
		}
	}
	int cnt=0;
	for(int z=0;z<l;z++){
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				if(pixel[x][y][z]==1&&inq[x][y][z]==false){
					cnt+=BFS(x,y,z);
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}