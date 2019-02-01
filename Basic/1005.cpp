#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000;
bool hashtable[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	int a[maxn];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=a[i];
		while(m!=1){
			if(m%2==1) m=(3*m+1)/2;
			else m/=2;
			hashtable[m]=true;
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		if(hashtable[a[i]]==false){
			count++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(hashtable[a[i]]==false){
			cout<<a[i];
			count--;
			if(count>0) cout<<' ';
		}
	}
	return 0;
}