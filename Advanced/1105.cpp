#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int N,num;
	cin>>N;
	vector<int>ans;
	for(int i=0;i<N;i++){
		cin>>num;
		ans.push_back(num);
	}
	if(N==1){
		cout<<ans[0];
		return 0;
	}
	sort(ans.begin(),ans.end(),cmp);
	int m=(int)ceil(sqrt(1.0*N));
	while(N%m!=0){
		m++;
	}
	int n=N/m;
	int i=1,j=1,U=1,D=m,L=1,R=n;
	int tot=0;
	int matrix[m+1][n+1];
	while(tot<N){
		while(tot<N&&j<R) matrix[i][j++]=ans[tot++];
		while(tot<N&&i<D) matrix[i++][j]=ans[tot++];
		while(tot<N&&j>L) matrix[i][j--]=ans[tot++];
		while(tot<N&&i>U) matrix[i--][j]=ans[tot++];
		i++,j++,U++,D--,L++,R--;
		if(tot==N-1) matrix[i][j]=ans[tot++];

	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<matrix[i][j];
			if(j<n)cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}