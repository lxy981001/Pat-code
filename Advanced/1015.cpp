#include<iostream>
#include<cmath>
using namespace std;
const int maxn=100010;
bool isPrime(int n){
	if(n<=1) return false;
	int sqr=(int )sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int d[111];
int main(){
	int n,radix;
	while(scanf("%d",&n)!=EOF){
		if(n<0 ) break;
		cin>>radix;
		if(isPrime(n)==false){
			cout<<"No"<<endl;
		}else{
			int len=0;
			do{
				d[len++]=n%radix;
				n/=radix;
			}while(n!=0);
			for(int i=0;i<len;i++){
				n=n*radix+d[i];
			}
			if(isPrime(n)==true) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}