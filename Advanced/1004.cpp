#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=110;
vector<int > tree[maxn];
int leafnum[maxn]={0};
int maxh=0;
int n,m;
int h[maxn]={0};
// void DFS(int index,int depth){
// 	maxh=max(depth,maxh);
// 	if(tree[index].size()==0){
// 		leafnum[depth]++;
// 		return;
// 	}
// 	for(int i=0;i<tree[index].size();i++){
// 		DFS(tree[index][i],depth+1);
// 	}
// }
void BFS(){
	queue<int >q;
	q.push(1);
	while(!q.empty()){
		int id=q.front();
		q.pop();
		maxh=max(maxh,h[id]);
		if(tree[id].size()==0){
			leafnum[h[id]]++;
		}
		for(int i=0;i<tree[id].size();i++){
			h[tree[id][i]]=h[id]+1;
			q.push(tree[id][i]);
		}
	}
}
int main(){
	cin>>n>>m;
	int child,parent,k;
	for(int i=0;i<m;i++){
		cin>>parent>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			tree[parent].push_back(child);
		}
	}
	h[1]=1;
	BFS();
	for(int i=1;i<=maxh;i++){
		if(i==1) cout<<leafnum[i];
		else cout<<' '<<leafnum[i];
	}
	// DFS(1,1);
	// if(n==1){
	// 	cout<<'1';
	// }else {
	// 	cout<<leafnum[0];
	// 	for(int i=2;i<=maxh;i++){
	// 		cout<<' '<<leafnum[i];
	// 	}
	// 
	
	return 0;
}