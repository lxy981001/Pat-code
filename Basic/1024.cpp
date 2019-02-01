#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	// char c,d,E='E';
	// string s;
	// int exp;
	// cin>>c;
	// getline(cin,s);
	// cin>>E>>d>>exp;
	// string temp=s;
	string s;
	getline(cin,s);
	for(string::iterator it=s.begin();it!=s.end();it++){
		if(*it=='.'){
			s.erase(it);
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	return 0;
}