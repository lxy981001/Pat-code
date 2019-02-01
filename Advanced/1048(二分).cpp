#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int num[maxn];
int bin(int a[],int left,int right,int x){
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) right=mid-1;
		else left=mid+1;
	}
	return -1;
}
int main(){
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	for(i=0;i<n;i++){
		int pos=bin(num,0,n-1,m-num[i]);
		if(pos!=-1&&pos!=i){
			cout<<num[i]<<' '<<num[pos];
			break;
		}
	}
	if(i==n) cout<<"No solution"<<endl;
	return 0;
}