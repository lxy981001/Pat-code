#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int hashtable[1010]={0};
int main(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		if(str[i]>='a'&&str[i]<='z'){
			hashtable[str[i]-'a']++;
		}else if(str[i]>='A'&&str[i]<='Z') {
			
			hashtable[str[i]-'A']++;
		}
	}
	int k=0;
	for(int i=0;i<26;i++){
		if(hashtable[i]>hashtable[k]){
			k=i;
		}
	}
	char c='a'+k;
	cout<<c<<' '<<hashtable[k];
	return 0;
}