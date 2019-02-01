#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>G[1010];
int n,m,a,b,k,flag=0,in[1010];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		in[b]++;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int judge=1;
		vector<int>tin(in,in+n+1);
		for(int j=0;j<n;j++){
			cin>>a;
			if(tin[a]!=0) judge=0;
			for(int l=0;l<G[a].size();l++){
				int p=G[a][l];
				tin[p]--;
			}
			
		}
	if(judge==1) continue;
	printf("%s%d",flag==1?" ":"",i);
	flag=1;
	}
	return 0;
}