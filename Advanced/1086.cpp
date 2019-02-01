#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int data;
	node* Left;
	node* Right;
};
vector<int> pre,in;
int n;
node* create(int preL,int preR,int inL,int inR){
	if(preL>preR)return NULL;
	node* root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL])break;
	}
	int numleft=k-inL;
	root->Left=create(preL+1,preL+numleft,inL,k-1);
	root->Right=create(preL+numleft+1,preR,k+1,inR);
	return root;
}
int num=0;
void postorder(node* root){
	if(root==NULL)return;
	postorder(root->Left);
	postorder(root->Right);
	cout<<root->data;
	num++;
	if(num<n) cout<<' ';
}
int main(){
	cin>>n;
	char str[5];
	stack<int> st;
	int x;
	for(int i=0;i<2*n;i++){
		cin>>str;
		if(strcmp(str,"Push")==0){
			cin>>x;
			pre.push_back(x);
			st.push(x);
		}else{
			in.push_back(st.top());
			st.pop();
		}
	}
	node* root=create(0,n-1,0,n-1);
	postorder(root);
	return 0;
}