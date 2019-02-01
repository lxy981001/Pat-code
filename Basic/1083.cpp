#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
	int n,num;
	cin>>n;
	int hash[10010]={0};
	for(int i=1;i<=n;i++){
		cin>>num;
		hash[abs(num-i)]++;
	}
	for(int i=9999;i>=0;i--){
		if(hash[i]>=2) cout<<i<<" "<<hash[i]<<endl;
	}
	return 0;
}