#include<iostream>
using namespace std;
int num[10];
int main(){
	int a,b;
	int sum;
	cin>>a>>b;
	sum=a+b;
	if(sum<0){
		cout<<"-";
		sum=-sum;
	}
	int len=0;
	if(sum==0) num[len++]=0;
	while(sum){
		num[len++]=sum%10;
		sum/=10;
	}
	for(int i=len-1;i>=0;i--){
		cout<<num[i];
		if(i>0&&i%3==0)cout<<",";
	}
	return 0;
}