#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int sum[maxn];
int n,m,nearm=100000010;
int upper_bound(int a[],int l,int r,int x){
	int left=l,right=r,mid;
	while(left<right){
		mid=(left+right)/2;
		if(a[mid]>x){
			right=mid;
		}else{
			left=mid+1;
		}
	}
	return left;
}
int main(){
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int j=upper_bound(sum,i,n+1,sum[i-1]+m);
		if(sum[j-1]-sum[i-1]==m){
			nearm=m;
			break;
		}else if(j<=n&&sum[j-1]-sum[i-1]<nearm){
			nearm=sum[j]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int j=upper_bound(sum,i,n+1,sum[i-1]+nearm);
		if(sum[j-1]-sum[i-1]==nearm){
			cout<<i<<"-"<<j-1<<endl;
		}
	}
	return 0;
}
