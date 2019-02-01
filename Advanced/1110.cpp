#include<iostream>
using namespace std;
struct node{
	int left,right;
} tree[100];
int maxn=-1,ans;
void dfs(int root,int index){
	if(index>maxn){
		maxn=index;
		ans=root;
	}
	if(tree[root].left!=-1) dfs(tree[root].left,index*2);
	if(tree[root].right!=-1) dfs(tree[root].right,index*2+1);
}
int main(){
	int n,root=0,have[100]={0};
	cin>>n;
	string l,r;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		if(l=="-"){
			tree[i].left=-1;
		}else {
			tree[i].left=stoi(l);
			have[stoi(l)]=1;
		}
		if(r=="-"){
			tree[i].right=-1;
		}else {
			tree[i].right=stoi(r);
			have[stoi(r)]=1;
		}
	}
	while(have[root]!=0) root++;
	dfs(root,1);
	if(maxn==n) cout<<"YES "<<ans;
	else cout<<"NO "<<root;	
	return 0;
}