#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	int maxn=0;
	cin>>n>>m;
	int moon[1005][1005],sum[1005];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){	
			cin>>moon[i][j];
			sum[j]+=moon[i][j];
			maxn=max(maxn,sum[j]);
		}
	}
	cout<<maxn<<endl;
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(sum[i]==maxn) ans.push_back(i);
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	return 0;
}