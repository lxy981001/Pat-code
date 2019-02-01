#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct fac{
	int x,cnt;
}factor[10];
bool isPrime(int n){
	int sqr=(int)sqrt(1.0*n);
	if(n==1) return false;
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;

	}
	return true;
}
int prime[maxn],pnum=0;
void find_Prime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i)==true){
			prime[pnum++]=i;
		}
	}
}
int main(){
	find_Prime();
	int n,num=0;
	cin>>n;
	if(n==1) cout<<"1=1"<<endl;
	else{
		cout<<n<<"=";
		int sqr=(int)sqrt(1.0*n);
		for(int i=0;i<pnumprime[i]<=sqr;i++){
			if(n%prime[i]==0){
				factor[num].x=prime[i];
				factor[num].cnt=0;
				while(n%prime[i]==0){
					factor[num].cnt++;
					n/=prime[i];
				}
				num++;
			}
			if(n==1) break;
		}
		if(n!=1){
			factor[num].x=n;
			factor[num++].cnt=1;
		}
		for(int i=0;i<num;i++){
			if(i>0) cout<<"*";
			cout<<factor[i].x;
			if(factor[i].cnt>1){
				cout<<"^"<<factor[i].cnt;
			}
		}
	}
	return 0;
}