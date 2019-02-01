#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int INF=999999999;
int leftMax[maxn],rightMin[maxn];
int main(){
	int n;
	cin>>n;
	int num[maxn];
	int temp[maxn],cnt=0;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}	
	leftMax[0]=0;
	for(int i=1;i<n;i++){
		leftMax[i]=max(leftMax[i+1],num[i-1]);
	}
	rightMin[n-1]=INF;
	for(int i=n-2;i>=0;i--){
		rightMin[i]=min(rightMin[i+1],num[i+1]);
	}
	for(int i=0;i<n;i++){
		if(leftMax[i]<num[i]&&rightMin[i]>num[i]){
			temp[cnt++]=num[i];
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		cout<<temp[i];
		if(i<cnt-1)cout<<' ';
	}
	return 0;
}