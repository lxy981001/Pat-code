#include<iostream>
#include<vector>
using namespace std;
vector<int>level,v;
int n;
void DFS(int root){
	if(root*2>n&&root*2+1>n){
		if(root<=n){
			for(int i=0;i<v.size();i++){
				cout<<v[i]<<(i!=v.size()-1?" ":"\n");
			}
		}
	}
	else{
		v.push_back(level[root*2+1]);
		DFS(root*2+1);
		v.pop_back();
		v.push_back(level[root*2]);
		DFS(root*2);
		v.pop_back();
	}
}
int main(){
	cin>>n;
	level.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>level[i];
	}
	v.push_back(level[1]);
	DFS(1);
	int flag=level[1]>level[2]?1:-1;
	for(int i=1;i<=(n-1)/2;i++){
		int left=i*2,right=i*2+1;
		if(flag==1&&(level[i]<level[left]||level[i]<level[right])) flag=0;
		if(flag==-1&&(level[i]>level[left]||level[i]>level[right])) flag=0;
	}	
	if(flag==0) cout<<"Not Heap";
	else cout<<(flag==1?"Max":"Min")<<" Heap";
	return 0;
}