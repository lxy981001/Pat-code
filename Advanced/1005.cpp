#include<iostream>
#include<string>
using namespace std;
string arr[15]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
	string str;
	cin>>str;
	int sum=0;
	for(int i=0;i<str.size();i++){
		sum+=(str[i]-'0');
	}
	string s=to_string(sum);
	cout<<arr[s[0]-'0'];
	for(int i=1;i<s.size();i++){
		cout<<" "<<arr[s[i]-'0'];
	}

	return 0;
}