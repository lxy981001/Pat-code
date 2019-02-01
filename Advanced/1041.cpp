#include<iostream>
using namespace std;
const int maxn=100010;
int hashtable[maxn]={0};
int a[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		hashtable[a[i]]++;
	}
	int ans=-1;
	for(int i=0;i<n;i++){
		if(hashtable[a[i]]==1){
			ans=a[i];
			break;
		}
	}if(ans==-1) cout<<"None";
	else cout<<ans<<endl;
	return 0;
}