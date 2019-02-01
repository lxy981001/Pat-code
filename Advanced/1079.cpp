#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
const int maxn=100010;
struct node{
	int data;
	vector<int > child;
} Node[maxn];
int n;
double p,r,ans=0;
void DFS(int index,int depth){
	if(Node[index].child.size()==0){
		ans+=Node[index].data*pow(r+1,depth);
		return;
	}
	for(int i=0;i<Node[index].child.size();i++){
		DFS(Node[index].child[i],depth+1);
	}
}
int main(){
	cin>>n>>p>>r;
	r/=100;
	int k,child;
	for(int i=0;i<n;i++){
		cin>>k;
		if(k==0){
			cin>>Node[i].data;
		}else{
			for(int j=0;j<k;j++){
				cin>>child;
				Node[i].child.push_back(child);
			}
		}
	}
	DFS(0,0);
	cout<<setiosflags(ios::fixed)<<setprecision(1)<<p*ans;
	return 0;
}