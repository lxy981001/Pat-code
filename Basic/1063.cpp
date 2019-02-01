#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,u,v;
	vector<double>ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>u>>v;
		double p=sqrt(u*u+v*v);
		ans.push_back(p);
		
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%.2f\n", *ans.begin());
	return 0;
}