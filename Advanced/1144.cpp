#include<iostream>
#include<map>
using namespace std;
int main(){
	map<int,int>mp;
	int n,a,num=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		mp[a]++;
	}
	while(++num){
		if(mp[num]==0) break;
	}
	cout<<num;
	return 0;
}