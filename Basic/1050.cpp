#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10010;
int ans[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int k,num;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>ans[i];
	}
	if(k==1){
		cout<<ans[0];
		return 0;
	}
	int m=(int)ceil(sqrt(1.0*k));
	while(k%m!=0){
		m++;
	}
	sort(ans,ans+k,cmp);
	int n=k/m,now=0,i=1,j=1;
	int up=1,down=m,left=1,right=n;
	int matrix[m+1][n+1];
	while(now<k){
		while(now<k&&j<right)matrix[i][j++]=ans[now++];
		while(now<k&&i<down) matrix[i++][j]=ans[now++];
		while(now<k&&j>left) matrix[i][j--]=ans[now++];
		while(now<k&&i>up) matrix[i--][j]=ans[now++];	
		i++,j++,up++,down--,left++,right--;
		if(now==k-1) matrix[i][j]=ans[now++];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d", matrix[i][j]);
			if(j<n) printf(" ");
			else printf("\n");
		}
	}

	return 0;
}