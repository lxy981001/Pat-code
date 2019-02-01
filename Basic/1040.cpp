#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=100010;
const int MOD=1000000007;
int leftnumP[maxn]={0};

int main(){
	string str;
	cin>>str;
	int len=str.length();
	for(int i=0;i<len;i++){
		if(i>0){
			leftnumP[i]=leftnumP[i-1];
		}
		if(str[i]=='P'){
			leftnumP[i]++;
		}
	}
	int sum=0,rightnumT=0;
	for(int i=len-1;i>=0;i--){
		if(str[i]=='T'){
			rightnumT++;
		}else if(str[i]=='A'){
			sum=(sum+leftnumP[i]*rightnumT)%MOD;
		}
	}
	cout<<sum;
	return 0;
}