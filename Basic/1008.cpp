#include<iostream>
using namespace std;
const int maxn=110;
int main(){
	int n,m,cnt=0;
	cin>>n>>m;
	int num[maxn];
	m=m%n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=n-m;i<n;i++){
		cout<<num[i];
		cnt++;
		if(cnt<n) cout<<' ';
	}
	for (int i = 0; i < n-m; ++i){
		cout<<num[i];
		cnt++;
		if(cnt<n) cout<<' ';
	}
	return 0;
}
/*#include<cstdio>
int main(){
	int n,m;
	int a[110];
	int cnt=0,i;
	scanf("%d %d",&n,&m);
	m=m%n;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=n-m;i<n;i++){
		printf("%d",a[i] );
		cnt++;
		if(cnt<n) printf(" ");
	}
	for(i=0;i<n-m;i++){
		printf("%d",a[i] );
		cnt++;
		if(cnt<n) printf(" " );
	}
	return 0;
}*/