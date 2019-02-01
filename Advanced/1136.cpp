#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a){
	string ans,temp=a;
	int len=a.length(),carry=0;
	reverse(temp.begin(),temp.end());
	for(int i=0;i<len;i++){
		int num=(a[i]-'0'+temp[i]-'0')+carry;
		carry=0;
		if(num>=10){
			num-=10;
			carry=1;
		}
		ans+=(num+'0');
	}
	if(carry==1)ans+='1';
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	string s;
	cin>>s;
	int cnt=0;
	while(cnt<10){
		string temp=s;
		reverse(temp.begin(),temp.end());
		if(temp==s) {
			cout<<s<<" is a palindromic number.";
			break;
		}else {
			cout<<s<<" + "<<temp<<" = "<<add(s)<<endl;
			s=add(s);
			cnt++;
		}
	}
	if(cnt==10) cout<<"Not found in 10 iterations.";
	return 0;
}