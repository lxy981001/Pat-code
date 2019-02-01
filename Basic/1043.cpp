#include<iostream>
#include <string>
using namespace std;
char dict[6]={'P','A','T','e','s','t'};
int hashtable[10]={0};
int main(){
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<6;j++){
			if(dict[j]==s[i]){
				hashtable[j]++;
				sum++;
			}
		}
	}
	while(sum>0){
		for(int i=0;i<6;i++){
			if(hashtable[i]>0){
				cout<<dict[i];
				sum--;
				hashtable[i]--;
			}
		}
	}
	return 0;
}