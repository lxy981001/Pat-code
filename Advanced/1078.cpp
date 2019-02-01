#include<iostream>
#include<cmath>
using namespace std;
const int maxn=10010;
bool isPrime(int n){
	if(n<=1) return false;
	int sqr=(int )sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
bool hashtable[maxn]={0};
int main(){
	int n,tsize,a;
	cin>>tsize>>n;
	while(isPrime(tsize)==false){
		tsize++;
	}
	for(int i=0;i<n;i++){
		cin>>a;
		int M=a%tsize;
		if(hashtable[M]==false){
			hashtable[M]=true;
			if(i==0) cout<<M;
			else cout<<' '<<M;
		}else{
			int step;
			for(step=1;step<tsize;step++){
				M=(a+step*step)%tsize;
				if(hashtable[M]==false){
					hashtable[M]=true;
					if(i==0)cout<<M;
					else cout<<' '<<M;
					break;
				}
			}
			if(step>=tsize){
				if(i>0) cout<<' ';
				cout<<"-";
			}
		}
	}
	return 0;
}