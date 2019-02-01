#include<iostream>
using namespace std;
int main(){
	string str,num;
	char t;
	cin>>t;
	getchar();
	getline(cin,str);
	int cnt=1;
	if(t=='C'){
		char pre=str[0];
		for(int i=1;i<str.length();i++){
			if(str[i]==pre) cnt++;
			else {
				if(cnt>=2) cout<<cnt;
				cout<<pre;
				pre=str[i];
				cnt=1;
			}
		}
		if(cnt>=2) cout<<cnt;
		cout<<pre;
	}
	else if(t=='D'){
		for(int i=0;i<str.length();i++){
			if(str[i]>='0'&&str[i]<='9') num+=str[i];
			else {
				if(num.length()>0) cnt=stoi(num);
				while(cnt--)cout<<str[i];
				cnt=1;
				num="";
			}
		}
	}
	return 0;
}