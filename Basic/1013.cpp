#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1000010;
int prime[maxn],num=0;
bool p[maxn]={0};
bool isPrime(int n){
	if(n<=1) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
void findPrime(int n){
	for(int i=1;i<=maxn;i++){
		if(isPrime(i)==true){
			prime[num++]=i;
			p[i]=true;
			if(num>=n) break;
		}
	}
}
int main(){
	int cnt=0;
	int m,n;
	cin>>m>>n;
	findPrime(n);
	for(int i=m;i<=n;i++){
		cout<<prime[i-1];
		cnt++;
		if(cnt%10!=0&&i<n) cout<<' ';
		else cout<<endl;
	}
	return 0;
}