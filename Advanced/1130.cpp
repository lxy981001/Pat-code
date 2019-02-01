#include<iostream>
#include<string>
using namespace std;
struct node{
	string data;
	int left,right;
}a[100];
string dfs(int root){
	if(a[root].left==-1&&a[root].right==-1) return a[root].data;
	if(a[root].left==-1&&a[root].right!=-1) return "("+a[root].data
		+dfs(a[root].right)+")";
	if(a[root].left!=-1&&a[root].right!=-1) return "("+dfs(a[root].left)
		+a[root].data+dfs(a[root].right)+")";
}
int main(){
	int n;
	int have[100]={0},root=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].data>>a[i].left>>a[i].right;
		if(a[i].left!=-1) have[a[i].left]=1;
		if(a[i].right!=-1) have[a[i].right]=1;
	}
	while(have[root]==1) root++;
	string ans=dfs(root);
	if(ans[0]=='(') ans=ans.substr(1,ans.size()-2);
	cout<<ans;
	return 0;
}