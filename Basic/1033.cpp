#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool hashtable[256];
string str;
int main(){
	memset(hashtable,true,sizeof(hashtable));
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i]+=32;
		}
		hashtable[str[i]]=false;
	}
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z'){
			int n=str[i]+32;
			if(hashtable[n]==true&&hashtable['+']==true){
				cout<<str[i];
			}
		}else if(hashtable[str[i]]==true){
			cout<<str[i];
		}
	}
	return 0;
}