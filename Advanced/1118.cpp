#include<iostream>
using namespace std;
const int maxn=10010;
int n;
int father[maxn],cnt[maxn]={0};
bool isExist[maxn];
void init(){
	for(int i=1;i<maxn;i++){
		father[i]=i;
	}
}
int findFather(int x){
	if(x==father[x])return x;
	else {
		int F=findFather(father[x]);
		father[x]=F;
		return F;
	}
}	
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB) father[faA]=faB;
}
int main(){
	init();
	cin>>n;
	int k,id,temp;
	for(int i=0;i<n;i++){
		cin>>k>>id;
		isExist[id]=true;
		for(int j=0;j<k-1;j++){
			cin>>temp;
			Union(temp,id);
			isExist[temp]=true;
		}
	}
	for(int i=1;i<=maxn;i++){
		if(isExist[i]==true){
			int root=findFather(i);
			cnt[root]++;
		}
	}
	int numTrees=0,numBirds=0;
	for(int i=1;i<=maxn;i++){
		if(isExist[i]==true&&cnt[i]!=0){
			numTrees++;
			numBirds+=cnt[i];
		}
	}
	cout<<numTrees<<' '<<numBirds<<endl;
	int m,ida,idb;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>ida>>idb;
		if(findFather(ida)!=findFather(idb)) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}