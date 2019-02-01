#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
double ans[100010];
int main(){
	int n;
	cin>>n;
	double result=0.0;
	for(int i=1;i<=n;i++){
		cin>>ans[i];
		result=result+ans[i]*i*(n-i+1);
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<result;
	return 0;
}