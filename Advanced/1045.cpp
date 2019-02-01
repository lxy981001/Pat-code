#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10010;
const int maxc=210;
int A[maxn],hashtable[maxc],dp[maxn];
int main(){
	int n,m,x;
	memset(hashtable,-1,sizeof(hashtable));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x;
		hashtable[x]=i;
	}
	int l,num=0;
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>x;
		if(hashtable[x]>=0){
			A[num++]=hashtable[x];
		}
	}
	int ans=-1;
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<=A[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}