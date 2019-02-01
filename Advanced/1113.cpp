#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	sort(v.begin(),v.end());
	int sum1=0;
	for(int i=0;i<n/2;i++){
		sum1+=v[i];
	}
	cout<<abs(n-n/2*2)<<" "<<abs(2*sum1-sum)<<endl;
	return 0;
}
