#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,num[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	int result=num[0];
	for(int i=1;i<n;i++){
		result=(result+num[i])/2;
	}
	cout<<result;
	return 0;
}