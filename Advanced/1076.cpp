#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
struct Node{
	int id;
	int layer;
};
vector<Node> Adj[maxn];
bool inq[maxn]={false};
int BFS(int s,int L){
	int numforward=0;
	queue<Node> q;
	Node start;
	start.id=s;
	start.layer=0;
	q.push(start);
	inq[start.id]=true;
	while(!q.empty()){
		Node topnode=q.front();
		q.pop();
		int u=topnode.id;
		for(int i=0;i<Adj[u].size();i++){
			Node next=Adj[u][i];
			next.layer=topnode.layer+1;
			if(inq[next.id]==false&&next.layer<=L){
				q.push(next);
				inq[next.id]=true;
				numforward++;
			}
		}
	}
	return numforward;
}
int main(){
	Node user;
	int n,l;
	int numfollow,idfollow;
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		user.id=i;
		cin>>numfollow;
		for(int j=0;j<numfollow;j++){
			cin>>idfollow;
			Adj[idfollow].push_back(user);
		}
	}
	int numQuerry,s;
	cin>>numQuerry;
	for(int i=0;i<numQuerry;i++){
		memset(inq,false,sizeof(inq));
		cin>>s;
		int numforward=BFS(s,l);
		cout<<numforward<<endl;
	}

	return 0;
}	