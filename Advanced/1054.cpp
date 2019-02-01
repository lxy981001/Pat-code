#include<iostream>
#include<map>
using namespace std;
int main(){
	std::map<int, int> cnt;//编号和个数的映射
	int m,n,col;
	cin>>m>>n;
	for(int i=0;i<m;i++){//行
		for(int i=0;i<n;i++){//列
			cin>>col;
			if(cnt.find(col)!=cnt.end()) cnt[col]++;
			else cnt[col]=1;
		}
	}
	int k=0,max=0;
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		if(it->second>max) {
			k=it->first;
			max=it->second;
		}
	}
	cout<<k;
	return 0;
}