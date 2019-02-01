#include<iostream>
#include<map>
using namespace std;
int main(){
	int m,n,s;
	cin>>m>>n>>s;
	map<string,int>mp;
	string str;
	bool flag=false;
	for(int i=1;i<=m;i++){
		cin>>str;
		while(i==s&&mp[str]!=1){
			cout<<str<<endl;
			mp[str]=1;
			flag=true;
			s+=n;
		}
		if(mp[str]==1)s+=1;
	}
	if(flag==false) cout<<"Keep going...";
	return 0;
}