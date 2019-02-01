#include<iostream>
#include<string>
#include<set>
using namespace std;
int change(int a){
	int sum=0;
	while(a!=0){
		int t=a%10;
		sum+=t;
		a/=10;
	}
	return sum;
}
int main(){
	int n,num;
	cin>>n;
	set<int>ans;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>num;
		ans.insert(change(num));
	}
	cout<<ans.size()<<endl;
	for(auto i=ans.begin();i!=ans.end();i++){
		if(i!=ans.begin()) cout<<" ";
		cout<<*i;
	}
	return 0;
}