#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct node{
	int data,next;
} list[maxn];
vector<int> v[4];
int main(){
	int start,n,k,address;
	cin>>start>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&list[address].data,&list[address].next);
	}
	int p=start;
	while(p!=-1){
		if(list[p].data<0){
			v[0].push_back(p);
		}else if(list[p].data>=0&&list[p].data<=k){
			v[1].push_back(p);
		}else v[2].push_back(p);
		p=list[p].next;
	}
	for(int i=0;i<v[1].size();i++){
		v[0].push_back(v[1][i]);
	}
	for(int i=0;i<v[2].size();i++){
		v[0].push_back(v[2][i]);
	}
	for(int i=0;i<v[0].size();i++){
		printf("%05d %d ",v[0][i],list[v[0][i]].data );
		if(i==v[0].size()-1) printf("-1\n");
		else printf("%05d\n",v[0][i+1] );
	}
	return 0;
}