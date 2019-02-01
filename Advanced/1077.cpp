#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	getchar();
	string temp;
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		reverse(s.begin(),s.end());
		int len=s.size();
		if(i==0){
			temp=s;
			continue;
		}else{
			int lentemp=temp.size();
			int minlen=min(len,lentemp);
			for(int j=0;j<minlen;j++){
				if(temp[j]!=s[j]){
					temp=temp.substr(0,j);
					break;
				}
			}
		}
	}
	reverse(temp.begin(),temp.end());
	if(temp.size()==0)temp="nai";
	cout<<temp;
	return 0;
}