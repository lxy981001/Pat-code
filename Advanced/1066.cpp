#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int data,height;
	node *left,*right;
} *root;
node* newnode(int v){
	node* root=new node;
	root->data=v;
	root->height=1;
	root->left=root->right=NULL;
	return root;
}
int getheight(node *root){
	if(root==NULL) return 0;
	return root->height;
}
void updateheight(node* root){
	root->height= max(getheight(root->right),getheight(root->left))+1;
}
int getBalance(node* root){
	return getheight(root->left)-getheight(root->right);
}
void R(node* &root){
	node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}
void L(node* &root){
	node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}
void insert(node* &root,int v){
	if(root==NULL){
		root=newnode(v);
		return;
	}
	if(v<root->data){
		insert(root->left,v);
		updateheight(root);
		if(getBalance(root)==2){
			if(getBalance(root->left)==1){
				R(root);
			}else if(getBalance(root->left)==-1){
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,v);
		updateheight(root);
		if(getBalance(root)==-2){
			if(getBalance(root->right)==-1){
				L(root);
			}else if(getBalance(root->right)==1){
				R(root->right);
				L(root);
			}
		}
	}
}

int main(){
	int n,v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v;
		insert(root,v);
	}
	cout<<root->data;
}