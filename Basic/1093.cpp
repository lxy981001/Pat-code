#include<iostream>
#include<string>
using namespace std;
int main(){
	int hash[1000]={0};
	string s1,s2,s;
	getline(cin,s1);
	getline(cin,s2);
	s=s1+s2;
	for(int i=0;i<s.size();i++){
		if(hash[s[i]]==0)cout<<s[i];
		hash[s[i]]=1;
	}
	return 0;
}