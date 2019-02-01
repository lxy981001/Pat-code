#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	while(cin>>s){
		if(s[2]=='T'&&s.size()==3) cout<<s[0]-'A'+1;
	}
	return 0;
}