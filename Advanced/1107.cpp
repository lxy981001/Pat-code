#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010;
int n;
int isRoot[maxn];
int father[maxn];
int course[maxn];
void init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
		isRoot[i]=false;
	}
}
int findfather(int x){
	if(x==father[x]) return x;
	else {
		int F=findfather(father[x]);
		father[x]=F;
		return F;
	}
}
void Union(int a,int b){
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB) father[faA]=faB;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	init(n);
	for(int i=1;i<=n;i++){
		int k,h;
		scanf("%d:",&k);
		for(int j=1;j<=k;j++){
			cin>>h;
			if(course[h]==0){
				course[h]=i;
			}
			Union(i,findfather(course[h]));
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		isRoot[findfather(i)]++;
	}
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0) ans++;
	}
	cout<<ans<<endl;
	sort(isRoot+1,isRoot+1+n,cmp);
	for(int i=1;i<=ans;i++){
		cout<<isRoot[i];
		if(i<ans) cout<<" ";
	}
	return 0;
}