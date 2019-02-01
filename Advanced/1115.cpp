#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int data;
	node *right,*left;
};
node *creatBSt(node *root,int v){
	if(root==NULL){
		root=new node;
		root->data=v;
		root->left=root->right=NULL;
	}
	else if(v<=root->data){
		root->left=creatBSt(root->left,v);
	}else root->right=creatBSt(root->right,v);
	return root;
}
int maxdepth=-1;
vector<int>num(1000);
void dfs(node* root,int depth){
	if(root==NULL){
		maxdepth=max(depth,maxdepth);
		return;
	}
	num[depth]++;
	dfs(root->left,depth+1);
	dfs(root->right,depth+1);
}
int main(){
	int n,t;
	cin>>n;
	node* root=NULL;
	for(int i=0;i<n;i++){
		cin>>t;
		root=creatBSt(root,t);
	}
	dfs(root,0);
	printf("%d + %d = %d\n",num[maxdepth-1],num[maxdepth-2],num[maxdepth-1]+num[maxdepth-2] );
	return 0;
}
