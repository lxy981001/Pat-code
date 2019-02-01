#include<iostream>
#include<set>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn=60;
set<int> num[maxn];
void compare(int a,int b){
	int totalnum=num[b].size(),samenum=0;
	for(set<int>::iterator it=num[a].begin();it!=num[a].end();it++){
		if(num[b].find(*it)!=num[b].end()) samenum++;
		else totalnum++;
	}
	double temp;
	temp=100.0*samenum/totalnum;
	cout<<setiosflags(ios::fixed)<<setprecision(1)<<temp<<'%'<<endl;
}
int main(){
	int n,k,v,q,set1,set2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>v;
			num[i].insert(v);
		}
	}

	cin>>q;
	for(int i=0;i<q;i++){
		cin>>set1>>set2;
		compare(set1,set2);
	}
	
	return 0;
}
