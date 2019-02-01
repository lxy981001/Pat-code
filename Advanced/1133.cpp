#include<iostream>
#include<vector>
using namespace std;
struct node{
	int data,address,next;
};
int main(){
	int begin,n,k;
	cin>>begin>>n>>k;
	node a[100000];
	vector<node>v,ans;
	for(int i=0;i<n;i++){
		int address,data,next;
		cin>>address>>data>>next;
		a[address].address=address;
		a[address].data=data;
		a[address].next=next;
	}
	while(begin!=-1){
		v.push_back(a[begin]);
		begin=a[begin].next;
	}
	for(int i=0;i<v.size();i++){
		if(v[i].data<0) ans.push_back(v[i]);
	}
	for(int i=0;i<v.size();i++){
		if(v[i].data<=k&&v[i].data>=0) ans.push_back(v[i]);
	}
	for(int i=0;i<v.size();i++){
		if(v[i].data>k) ans.push_back(v[i]);
	}
	for(int i=0;i<v.size()-1;i++){
		printf("%05d %d %05d\n",ans[i].address,ans[i].data,ans[i+1].address );
	}
	printf("%05d %d -1\n",ans[ans.size()-1].address,ans[ans.size()-1].data );
	return 0;
}