#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=110;
struct node{
	int data;
	int left,right;
}Node[maxn];
int in[maxn],n,num=0;
void inorder(int root){
	if(root==-1) return;
	inorder(Node[root].left);
	Node[root].data=in[num++];
	inorder(Node[root].right);
}
void BFS(int root){
	queue<int > q;
	q.push(root);
	num=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		cout<<Node[now].data;
		num++;
		if(num<n) cout<<" ";
		if(Node[now].left!=-1) q.push(Node[now].left); 
		if(Node[now].right!=-1) q.push(Node[now].right); 
	}
}
int main(){
	int left,right;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>left>>right;
		Node[i].left=left;
		Node[i].right=right;
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	sort(in,in+n);
	inorder(0);
	BFS(0);
	return 0;
}