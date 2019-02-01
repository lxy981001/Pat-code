#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
vector<int> child[maxn];
int n;
double p,r,ans=0;
int num=0,maxdepth=0;
void DFS(int index,int depth){
	if(child[index].size()==0){
		if(depth>maxdepth){
			maxdepth=depth;
			num=1;
		}else if(depth==maxdepth){
			num++;
		}
		return ;
	}
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
}	
int main(){
	cin>>n>>p>>r;
	r/=100;
	int father,root;
	for(int i=0;i<n;i++){
		cin>>father;
		if(father!=-1){
			child[father].push_back(i);
		}else{
			root=i;
		}
	}
	DFS(root,0);
	printf("%.2f %d",p*pow(r+1,maxdepth),num);
	return 0;
}