#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m,a,b,k,nv,num;
	cin>>n>>m;
	vector<int>v[n];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a].push_back(i);
		v[b].push_back(i);
	}
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>nv;
		int flag=0;
		vector<int> hash(m,0);
		for(int j=0;j<nv;j++){
			cin>>num;
			for(int t=0;t<v[num].size();t++){
				hash[v[num][t]]=1;
			}
		}
		for(int j=0;j<m;j++){
			if(hash[j]==0){
				cout<<"No"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)cout<<"Yes"<<endl;
	}
	return 0;
}