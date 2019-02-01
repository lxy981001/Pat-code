#include<iostream>
#include<vector>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
void insert(node* &root,int data){
	if(root==NULL){
		root= new node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data) insert(root->left,data);
	else insert(root->right,data);
}
void preorder(node* root,std::vector<int> &v){
	if(root==NULL) return;
	v.push_back(root->data);
	preorder(root->left,v);
	preorder(root->right,v);
}
void preorderMirror(node* root,std::vector<int> &v){
	if(root==NULL) return;
	v.push_back(root->data);
	preorderMirror(root->right,v);
	preorderMirror(root->left,v);
}	
void postorder(node* root,std::vector<int> &v){
	if(root==NULL)return;
	postorder(root->left,v);
	postorder(root->right,v);
	v.push_back(root->data);
}
void postorderMirror(node* root,std::vector<int> &v){
	if(root==NULL)return;
	postorderMirror(root->right,v);
	postorderMirror(root->left,v);
	v.push_back(root->data);
}
vector<int> origin,pre,preM,post,postM;
int main(){
	int n,data;
	node* root=NULL;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data;
		origin.push_back(data);
		insert(root,data);
	}
	preorder(root,pre);
	preorderMirror(root,preM);
	postorder(root,post);
	postorderMirror(root,postM);
	if(origin==pre){
		cout<<"YES"<<endl;
		for(int i=0;i<post.size();i++){
			cout<<post[i];
			if(i<post.size()-1) cout<<" ";
		}
	}else if(origin==preM){
		cout<<"YES"<<endl;
		for(int i=0;i<postM.size();i++){
			cout<<postM[i];
			if(i<postM.size()-1)cout<<" ";
		}
	}else {
		cout<<"NO";
	}
	return 0;
}