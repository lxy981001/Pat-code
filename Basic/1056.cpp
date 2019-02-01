#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[20];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=(n-1)*a[i]*10;
		sum+=a[i]*(n-1);
	}
	cout<<sum;
	return 0;
}