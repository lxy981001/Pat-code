#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string s=to_string(n*m);
	reverse(s.begin(),s.end());
	cout<<stoi(s);
	return 0;
}