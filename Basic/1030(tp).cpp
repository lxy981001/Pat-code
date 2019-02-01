#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
typedef long long LL;
LL num[maxn];
int main(){
	LL n,p;
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n); 
	int count=0;
	int i=0,j=0;
	while(i<n){
		while(j<n&&num[j]<=num[i]*p){
			count=max(count,j-i+1);
			j++;
		}
		i++;
	}
	cout<<count<<endl;
	return 0;
}