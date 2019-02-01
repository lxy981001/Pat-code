#include<iostream>
#include<set>
#include<vector>
using namespace std;
struct node{
	int a,b;
};
int main(){
	int n,m,k;
	cin>>n>>m;
	vector<node>v(n);
	for(int i=0;i<m;i++){
		cin>>v[i].a>>v[i].b;
	}
	cin>>k;
	while(k--){
		bool flag=true;
		int hash[10010]={0};
		set<int>se;
		for(int i=0;i<n;i++){
			cin>>hash[i];
			se.insert(hash[i]);
		}
		for(int i=0;i<m;i++){
			if(hash[v[i].a]==hash[v[i].b]){
				flag=false;
				break;
			}
		}
		if(flag)printf("%d-coloring\n",se.size() );
		else printf("NO\n");
	}
	return 0;
}