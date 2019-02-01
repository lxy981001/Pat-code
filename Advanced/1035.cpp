#include<iostream>
#include<string>
using namespace std;
const int maxn=1010;
struct node{
	string acc,password;
	bool flag;
} user[maxn];
bool judge(string s){
	if(s.find("1")!=-1||s.find("0")!=-1||s.find("l")!=-1||s.find("O")!=-1) return true;
	else return false;
}
string change(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')s[i]='@';
		if(s[i]=='0')s[i]='%';
		if(s[i]=='l')s[i]='L';
		if(s[i]=='O')s[i]='o';
	}
	return s;
}
int main(){
	int n;
	cin>>n;
	int cnt=0,len=0;
	for(int i=0;i<n;i++){
		cin>>user[i].acc>>user[i].password;
		user[i].flag=false;
		if(judge(user[i].password)){
			user[i].flag=true;
			cnt++;
		}
	}
	if(cnt==0){
		if(n!=1){
			cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		}else{
			cout<<"There is 1 account and no account is modified"<<endl;
		}
	}
	else{
		cout<<cnt<<endl;
		for(int i=0;i<n;i++){
			if(user[i].flag==true){
				cout<<user[i].acc<<" "<<change(user[i].password)<<endl;
			}
		}
	}
	return 0;
}