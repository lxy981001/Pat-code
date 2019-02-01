#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10010;
int hashtable[maxn];
int main(){
	int n,m,a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		hashtable[a]++;
	}
	for(int i=1;i<m;i++){
		if(hashtable[i]&&hashtable[m-i]){
			if(i==m-i&&hashtable[i]<=1){
				continue;
			}
			cout<<i<<' '<<m-i;
			return 0;
		}
	}
	cout<<"No Solution";
	return 0;
}