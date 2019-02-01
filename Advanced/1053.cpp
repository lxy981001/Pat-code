#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=110;
struct node{
	int weight;
	vector<int > child;
} Node[maxn];
int n,m,s;
int path[maxn];
bool cmp(int a,int b){
	return Node[a].weight>Node[b].weight;
}
void DFS(int index,int numnode,int sum){
	if(sum>s) return;
	if(sum==s){
		if(Node[index].child.size()!=0) return;
		for(int i=0;i<numnode;i++){
			cout<<Node[path[i]].weight;
			if(i<numnode-1) cout<<" ";
			else cout<<endl;
		}
		return;
	}
	for(int i=0;i<Node[index].child.size();i++){
		int child=Node[index].child[i];
		path[numnode]=child;
		DFS(child,numnode+1,sum+Node[child].weight);
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>Node[i].weight;
	}
	int id,k,child;
	for(int i=0;i<m;i++){
		cin>>id>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);
	}
	path[0]=0;
	DFS(0,1,Node[0].weight);
	return 0;
}