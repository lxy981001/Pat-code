#include<iostream>
#include<vector>
using namespace std;
const int maxn=110;
vector<int > node[maxn];
int n,m;
int hashtable[maxn]={0};
void DFS(int index,int level){
	hashtable[level]++;
	for(int i=0;i<node[index].size();i++){
		DFS(node[index][i],level+1);
	}
}
int main(){
	cin>>n>>m;
	int id,k,child,parent;
	for(int i=0;i<m;i++){
		cin>>parent>>k;	
		for(int j=0;j<k;j++){
			cin>>child;
			node[parent].push_back(child);
		}
	}
	DFS(1,1);
	int maxlevel=-1,maxpeople=0;
	for(int i=1;i<maxn;i++){
		if(hashtable[i]>maxpeople){
			maxpeople=hashtable[i];
			maxlevel=i;
		}
	}
	cout<<maxpeople<<' '<<maxlevel;
	return 0;
}