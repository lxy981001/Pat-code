#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int change(int n){
	int ans=0;
	while(n){
		int m=n%10;
		ans+=m;
		n/=10;
	}
	return ans;
}
int main(){
	int n,m;
	cin>>n;	
	set<int >p;
	for(int i=0;i<n;i++){
		cin>>m;
		p.insert(change(m));
	}
	cout<<p.size()<<endl;
	for(set<int>::iterator it=p.begin();it!=p.end();it++){
		if(it!=p.begin()) cout<<" ";
		cout<<*it;
	}
	return 0;
}