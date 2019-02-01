#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=10010;
int hashtable[maxn];
int main(){
	memset(hashtable,0,sizeof(hashtable));
	int n,m,score;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>score;
		hashtable[score]++;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>score;
		cout<<hashtable[score];
		if(i<m-1) cout<<' ';
	}
	return 0;
}