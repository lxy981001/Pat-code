#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<vector<int> >matrix;
int n,m,tol;
int dist[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};
bool judge(int x,int y){
	for(int i=0;i<8;i++){
		int tx=x+dist[i][0];
		int ty=y+dist[i][1];
		if(tx>=0&&tx<n&&ty>=0&&ty<m&&matrix[x][y]-matrix[tx][ty]>=0-tol
			&&matrix[x][y]-matrix[tx][ty]<=tol)return false;
	}
	return true;
}
int main(){
	int x=0,y=0,cnt=0;
	map<int,int>p;
	cin>>m>>n>>tol;
	matrix.resize(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
			p[matrix[i][j]]++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(p[matrix[i][j]]==1&&judge(i,j)==true){
				cnt++;
				x=i+1;
				y=j+1;
			}
		}
	}
	if(cnt==1) cout<<"("<<y<<", "<<x<<"): "<<matrix[x-1][y-1];
	else if(cnt==0) cout<<"Not Exist";
	else cout<<"Not Unique";
	return 0;
}