#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,cnt=0;
	cin>>n;
	vector<int>ans(100000);
	for(int i=0;i<n;i++){
		cin>>ans[i];
	}
	sort(ans.begin(),ans.end(),cmp);
	while(cnt<n&&ans[cnt]>cnt+1){
		cnt++;
	}
	cout<<cnt;
	return 0;
}