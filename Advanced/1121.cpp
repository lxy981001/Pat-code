#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
	int n,u,v,m;
	cin>>n;
	vector<int>couple(100000);
	for(int i=0;i<100000;i++){
		couple[i]=-1;
	}
	for(int i=0;i<n;i++){
		cin>>u>>v;
		couple[u]=v;
		couple[v]=u;
	}
	cin>>m;
	vector<int>guest(m),isExist(100000);
	for(int i=0;i<m;i++){
		cin>>guest[i];
		if(couple[guest[i]]!=-1) isExist[guest[i]]=1;
	}
	set<int>ans;
	for(int i=0;i<m;i++){
		if(!isExist[couple[guest[i]]]) ans.insert(guest[i]);
	}
	printf("%d\n", ans.size());
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it!=ans.begin()) printf(" ");
		printf("%05d",*it );
	}
	return 0;
}