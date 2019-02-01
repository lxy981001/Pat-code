#include<iostream>
#include <iomanip>
using namespace std;
const int maxn=100010;
int main(){
	int n;
	cin>>n;
	double num;
	double sum=0;
	for(int i=1;i<=n;i++){
		cin>>num;
		sum+=num*i*(n+1-i);
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
	return 0;
}	