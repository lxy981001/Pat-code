#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
const int INF=1e12;
vector<int > node[maxn];
int n;
double p,r;
int num=0;
double ans=INF;
void DFS(int index,int depth){
	if(node[index].size()==0){
		double price=p*pow(r+1,depth);
		if(price<ans){
			ans=price;
			num=1;
		}else if(price==ans){
			num++;
		}
		return;
	}
	for(int i=0;i<node[index].size();i++){
		DFS(node[index][i],depth+1);
	}
}
int main(){
	int child,k;
	cin>>n>>p>>r;
	r/=100;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			node[i].push_back(child);
		}
	}
	DFS(0,0);
	printf("%.4f %d\n",ans,num );
	return 0;
}