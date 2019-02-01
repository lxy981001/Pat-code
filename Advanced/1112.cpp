#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(){
	int k,cnt=1;
	cin>>k;
	string s;
	cin>>s;
	char pre='!';
	s+='!';
	bool flag[200]={false};
	map<char,bool>m;
	set<char>printed;
	for(int i=0;i<s.length();i++){
		if(s[i]==pre) cnt++;
		else {
			if(cnt%k!=0) flag[pre]=true;
			cnt=1;
		}
		if(i!=s.length()-1) m[s[i]]=(cnt%k==0);
		pre=s[i];
	}
	for(int i=0;i<s.length()-1;i++){
			if(flag[s[i]]==true) 
				m[s[i]]=false;
	}
	for(int i=0;i<s.length()-1;i++){
		if(m[s[i]]==true&&printed.find(s[i])==printed.end()){
			cout<<s[i];
			printed.insert(s[i]);
		}
	}
	cout<<endl;
	for(int i=0;i<s.length()-1;i++){
		cout<<s[i];
		if(m[s[i]]) i=i+k-1;
	}
	return 0;
}