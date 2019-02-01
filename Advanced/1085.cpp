#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100010;
LL num[maxn];
int main(){
	int n,p;
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	int sum=1;
	for(int i=0;i<n;i++){
		int j=upper_bound(num+i+1,num+n,num[i]*p)-num;
		sum=max(sum,j-i);
	}
	cout<<sum;
	return 0;
}