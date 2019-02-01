#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
int Rank[10000];
int main(){
	int n,id;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>id;
		Rank[id]=i+1;
	}
	set<int>flag;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>id;
		printf("%04d: ",id );
		if(Rank[id]==0){
			printf("Are you kidding?\n");
			continue;
		}
		if(flag.find(id)==flag.end()){
			flag.insert(id);
		}else {
			printf("Checked\n");
			continue;
		}
		if(Rank[id]==1) printf("Mystery Award\n");
		else if(isPrime(Rank[id])) printf("Minion\n");
		else printf("Chocolate\n");
	}
	return 0;
}