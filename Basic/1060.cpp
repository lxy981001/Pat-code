#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,cnt=0;
	cin>>n;
	int dist[100010];
	for(int i=1;i<=n;i++){
		cin>>dist[i];
	}
	sort(dist+1,dist+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(dist[i]>i) cnt++;
	}
	cout<<cnt;
	return 0;
}