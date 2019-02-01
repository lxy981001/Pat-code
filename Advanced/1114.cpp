#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10010;
int father[maxn];
bool visit[maxn];
struct DATA{
	int id,fid,mid,num,area;
	int cid[10];
}data[1005];
struct node{
	int id,people;
	double num,area;
	bool flag;
} ans[maxn];
int findFather(int x){
	if(x==father[x]) return x;
	else{
		int F=findFather(father[x]);
		father[x]=F;
		return F;
	}
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA<faB) father[faB]=faA;
	else if(faA>faB) father[faA]=faB;
}
bool cmp(node a,node b){
	if(a.area!=b.area) return a.area>b.area;
	else return a.id<b.id;
}
void init(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
}
int main(){
	int n,k,cnt=0;
	scanf("%d",&n);
	init();
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&data[i].id,&data[i].fid,&data[i].mid,&k);
		visit[data[i].id]=true;
		if(data[i].fid!=-1){
		 	Union(data[i].fid,data[i].id);
		 	visit[data[i].fid]=true;
		}
		if(data[i].mid!=-1){
		 	Union(data[i].mid,data[i].id);
		 	visit[data[i].mid]=true;
		}
		for(int j=0;j<k;j++){	
			scanf("%d",&data[i].cid[j]);
			visit[data[i].cid[j]]=true;
			Union(data[i].cid[j],data[i].id);
		}
		scanf("%d %d",&data[i].num,&data[i].area);
	}
	for(int i=0;i<n;i++){
		int id=findFather(data[i].id);
		ans[id].id=id;
		ans[id].num+=data[i].num;
		ans[id].area+=data[i].area;
		ans[id].flag=true;
	}
	for(int i=0;i<maxn;i++){
		if(visit[i]) ans[findFather(i)].people++;
		if(ans[i].flag) cnt++;
	}
	for(int i=0;i<maxn;i++){
		if(ans[i].flag){
			ans[i].num=(double) (ans[i].num*1.0/ans[i].people);
			ans[i].area=(double) (ans[i].area*1.0/ans[i].people);
		}
	}
	sort(ans,ans+maxn,cmp);
	printf("%d\n",cnt );
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area );
	}
	return 0;
}