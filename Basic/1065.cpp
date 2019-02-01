#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
const int maxn=100010;
using namespace std;
int main(){
	vector<int>dog(maxn,-1);
	int n,m;
	cin>>n;
	int u,v;
	for(int i=0;i<n;i++){
		cin>>u>>v;
		dog[u]=v;
		dog[v]=u;
	}
	cin>>m;
	int cnt=0;
	vector<int>inq(m),isDog(maxn);
	for(int i=0;i<m;i++){
		cin>>inq[i];
		if(dog[inq[i]]!=-1){
			isDog[dog[inq[i]]]=1;
		}
	}
	set<int >s;
	for(int i=0;i<m;i++){
		if(!isDog[inq[i]]) s.insert(inq[i]);
	}
	cout<<s.size()<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();it++){	
		if(it!=s.begin())cout<<" ";
		printf("%05d",*it );
	}
	return 0;
}