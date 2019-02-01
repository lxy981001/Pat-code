#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a,string b){
	string ans;
	int carry=0;
	for(int i=0;i<a.length();i++){
		int num=(a[i]-'0'+b[i]-'0')+carry;
		carry=0;
		if(num>=10){
			num-=10;
			carry=1;
		}
		ans+=(num+'0');
	}
	if(carry==1) ans+='1';
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	string str;
	int cnt=0;
	cin>>str;
	while(cnt<10){
		string temp=str;
		reverse(temp.begin(),temp.end());
		if(temp==str){
			cout<<str<<" is a palindromic number."<<endl;
			break;
		}else {
			cout<<str<<" + "<<temp<<" = "<<add(str,temp)<<endl;
			cnt++;
			str=add(str,temp);
		}
	}
	if(cnt==10)cout<<"Not found in 10 iterations."<<endl;
	return 0;
}