#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	getchar();
	string s;
	for(int i=0;i<n;i++){
		getline(cin,s);
		if(s.length()>=6){
			int invalid=0,hasAlpha=0,hasNum=0;
			for(int j=0;j<s.length();j++){	
				if(!isalnum(s[j])&&s[j]!='.') invalid=1;
				else if(isalpha(s[j])) hasAlpha=1;
				else if(isdigit(s[j])) hasNum=1;
			}
			if(invalid==1) cout<<"Your password is tai luan le."<<endl;
			else if(hasNum==0) cout<<"Your password needs shu zi."<<endl;
			else if(hasAlpha==0) cout<<"Your password needs zi mu."<<endl;
			else cout<<"Your password is wan mei."<<endl;
		}else {
			cout<<"Your password is tai duan le."<<endl;
		}
	}
	return 0;
}