#include<iostream>
#include<string>
#include <cstring>
using namespace std;
int vis[10];
int main(){
	string s;
	cin>>s;
	int carry=0,len=s.length();
	for(int i=len-1;i>=0;i--){
		int temp=s[i]-'0';
		vis[temp]++;
		temp=temp*2+carry;
		carry=0;
		if(temp>=10){
			temp-=10;
			carry=1;
		}
		s[i]=(temp+'0');
		vis[temp]--;
	}
	int flag=0;
	for(int i=0;i<10;i++){
		if(vis[i]!=0){
			flag=1;
		}
	}	
	if(flag==1||carry==1) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	if(carry==1) cout<<"1";
	cout<<s;
	return 0;
}
