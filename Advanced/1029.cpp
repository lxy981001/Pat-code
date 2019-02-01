#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000010;
int num1[maxn];
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num1[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>num1[i+n];
	}
	sort(num1,num1+n+m);
	cout<<num1[(n+m-1)/2];
	return 0;
}