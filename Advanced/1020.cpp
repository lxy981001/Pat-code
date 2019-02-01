#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=50;
int n;
int post[maxn],in[maxn],layer[maxn];
struct node{
	int data;
	node* Left;
	node* Right;
};
node* creat(int postL,int postR,int inL, int inR){
	if(postL>postR) return NULL;
	node* root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR]) break;
	}
	int numleft=k-inL;
	root->Left=creat(postL,postL+numleft-1,inL,k-1);
	root->Right=creat(postL+numleft,postR-1,k+1,inR);
	return root;
}
int num=0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		cout<<now->data;
		num++;
		if(num<n) cout<<' ';
		if(now->Left!=NULL) q.push(now->Left);
		if(now->Right!=NULL) q.push(now->Right);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	node* root=creat(0,n-1,0,n-1);
	BFS(root);
	return 0;
}