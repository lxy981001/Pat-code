#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int main(){
	int n,m;
	int num[maxn];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	int i=0,j=n-1;
	while(i<j){
		if(num[i]+num[j]==m) break;
		else if(num[i]+num[j]<m) i++;
		else j--;
	}
	if(i<j) cout<<num[i]<<' '<<num[j];
	else cout<<"No Solution";
	return 0;
}