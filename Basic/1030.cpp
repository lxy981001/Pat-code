#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100010;
LL num[maxn];
LL n,p;
int binarySearch(LL a[],int i,LL x){
	if(a[n-1]<=x) return n;
	int l=i+1,r=n-1,mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]<=x){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return l;
}
int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	int sum=1;
	for(int i=0;i<n;i++){
		int j=binarySearch(num,i,num[i]*p);
		sum=max(sum,j-i);
	}
	cout<<sum;
	return 0;
}