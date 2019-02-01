#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		string s=to_string(num);
		int len=s.length();
		int a=stoi(s.substr(0,len/2));
		int b=stoi(s.substr(len/2));
		if(a*b!=0&&num%(a*b)==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}	
	return 0;
}