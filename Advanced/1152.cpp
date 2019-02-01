#include<iostream>
#include<string>
using namespace std;
bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	for(int i=0;i<=n-k;i++){
		string s1=str.substr(i,k);
		int temp=stoi(s1);
		if(isPrime(temp)){
			cout<<s1;
			return 0;
		} 
	}
	cout<<"404";
	return 0;
}