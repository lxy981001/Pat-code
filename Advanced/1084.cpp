#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1,str2;
	cin>>str1>>str2;
	bool hashtable[128]={false};
	for(int i=0;i<str1.length();i++){
		int j=0;
		char c1,c2;
		for(j=0;j<str2.length();j++){
			c1=str1[i];
			c2=str2[j];
			if(c1>='a'&&c1<='z') c1-=32;
			if(c2>='a'&&c2<='z') c2-=32;
			if(c1==c2) break;
		}
		if(j==str2.length()&&hashtable[c1]==false){
			cout<<c1;
			hashtable[c1]=true;
		}
	}
	return 0;
}