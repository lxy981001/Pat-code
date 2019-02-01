#include<iostream>
#include <algorithm>
using namespace std;
const int maxn=10010;
const int maxc=210;
int a[maxn],b[maxn],dp[maxc][maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int l;
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>b[i];
	}
	for(int i=0;i<=m;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<=l;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=l;j++){
			int MAX=max(dp[i-1][j],dp[i][j-1]);
			if(a[i]==b[j]){
				dp[i][j]=MAX+1;
			}else{
				dp[i][j]=MAX;
			}
		}
	}
	cout<<dp[m][l]<<endl;
	return 0;
}