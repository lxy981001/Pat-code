#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sqr=sqrt(1.0*n);
	int maxcount=0;
	int first;
	for(int i=2;i<=sqr;i++){
		int temp=n;
		int start=i;
		int count=0;
		while(temp%start==0){
			count++;
			temp/=start;
			start++;
		}
		if(start-i>maxcount){
			maxcount=start-i;
			first=i;
		}
	}
	if(maxcount==0){
		cout<<1<<endl;
		cout<<n;
	}else{
		cout<<maxcount<<endl;
		cout<<first;
		for(int i=1;i<maxcount;i++){
			cout<<"*"<<first+i;
		}
	}
	return 0;
}	