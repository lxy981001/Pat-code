#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=110;
struct node{
	int left,right;
} Node[maxn];
bool notroot[maxn]={false};
int n,num=0;
int strTonum(char c){
	if(c=='-') return -1;
	else{
		notroot[c-'0']=true;
		return c-'0';
	}
}
int findroot(){
	for(int i=0;i<n;i++){
		if(notroot[i]==false){
			return i;
		}
	}
}
void postorder(int root){
	if(root==-1){
	 return;
	}
	postorder(Node[root].left);
	postorder(Node[root].right);
	swap(Node[root].left,Node[root].right);
}
void print(int x){
	cout<<x;
	num++;
	if(num<n) cout<<' ';
	else cout<<endl;
}
void inorder(int root){
	if(root == -1){
	 	return;
	}
	inorder(Node[root].left);
	print(root);
	inorder(Node[root].right);
}
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		print(now);
		if(Node[now].left!=-1) q.push(Node[now].left);
		if(Node[now].right!=-1) q.push(Node[now].right);
	}
}

int main(){	
	char left,right;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>left>>right;
		Node[i].left=strTonum(left);
		Node[i].right=strTonum(right);
	}
	int root=findroot();
	postorder(root);
	BFS(root);
	num=0;
	inorder(root);
	return 0;
}