#include<iostream>
using namespace std;
int main(){
	string a;
	int b;
	cin>>a>>b;
	int temp;
	int len=a.length();
	int t=0;
	t=(a[0]-'0')/b;
	if((t!=0&&len>1)||len==1){
		cout<<t;
	}
	temp=(a[0]-'0')%b;
	for(int i=1;i<len;i++){
		t=((temp*10)+a[i]-'0')/b;
		cout<<t;
		temp=(temp*10+a[i]-'0')%b;
	}
	cout<<" "<<temp;
	return 0;
}