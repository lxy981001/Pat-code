#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m,l,r,temp;
	cin>>n>>m>>l>>r>>temp;
	int matrix[n+2][m+2];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
			if(matrix[i][j]>=l&&matrix[i][j]<=r){
				matrix[i][j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j!=0) printf(" ");
			printf("%03d",matrix[i][j]);
		}
		 printf("\n");
	}
	return 0;
}