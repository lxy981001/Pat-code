#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int >ans(n);
	for(int i=0;i<n;i++){
		cin>>ans[i];
	}
	sort(ans.begin(),ans.end());
	int result=ans[0];
	for(int i=1;i<n;i++){
		result=(ans[i]+result)/2;
	}
	cout<<result;
	return 0;
}