#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	int m,n,s;
	cin>>n>>m>>s;
	string str;
	map<string,int>bingo;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>str;
		if(bingo[str]==1) s+=1;
		if(i==s&&bingo[str]==0){
			s+=m;
			cout<<str<<endl;
			bingo[str]=1;
			flag=true;
		}
	}
	if(flag==false) cout<<"Keep going...";
	return 0;
}