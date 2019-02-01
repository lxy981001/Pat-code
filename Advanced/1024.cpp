#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
void add(string t){
	int carry=0;
	for(int i=0;i<t.length();i++){
		s[i]=t[i]+s[i]+carry-'0';
		carry=0;
		if(s[i]>'9'){
			s[i]=s[i]-10;
			carry=1;
		}
	}
	if(carry) s+='1';
	reverse(s.begin(),s.end());
}

int main(){
	int n,i;
	cin>>s>>n;
	for(i=0;i<=n;i++){
		string t=s;
		reverse(t.begin(),t.end());
		if(s==t||i==n) break;
		add(t);
	}
	cout<<s<<endl<<i;
	return 0;
}