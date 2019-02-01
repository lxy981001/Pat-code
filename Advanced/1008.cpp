#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num[110];
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	 num[0]=0;
	int sum=5*n;
	for(int i=1;i<=n;i++){
		if(num[i]-num[i-1]<0){
			sum=sum+(num[i-1]-num[i])*4;
		}else sum=sum+(num[i]-num[i-1])*6;
	}
	cout<<sum;
	return 0;
}