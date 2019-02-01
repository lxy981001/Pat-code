#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string password;
	int n,cnt=0;
	cin>>password>>n;
	getchar();
	string temp;
	while(1){
		getline(cin,temp);
		if(temp=="#")break;
		cnt++;
		if(cnt<=n&&temp==password){
			cout<<"Welcome in"<<endl;
			break;
		}else if(cnt<=n&&temp!=password){
			cout<<"Wrong password: "<<temp<<endl;
			if(cnt==n){
				cout<<"Account locked";
				break;
			}
		}
	}
	return 0;
}