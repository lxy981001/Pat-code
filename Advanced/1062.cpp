#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node{
	char id[10];
	int Vir;
	int Tal;
	int flag;
	int sum;
} stu[100010];
bool cmp(Node a,Node b){
	if(a.flag!=b.flag) return a.flag<b.flag;
	else if(a.sum!=b.sum) return a.sum>b.sum;
	else if(a.Vir!=b.Vir) return a.Vir>b.Vir;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,L,H;
	scanf("%d %d %d",&n,&L,&H);
	int m=n;
	for(int i=0;i<n;i++){
		scanf("%s %d %d",stu[i].id,&stu[i].Vir,&stu[i].Tal);
		stu[i].sum=stu[i].Vir+stu[i].Tal;
		if(stu[i].Vir<L||stu[i].Tal<L){
			stu[i].flag=5;
			m--;
		}
		else if(stu[i].Vir>=H&&stu[i].Vir>=H) stu[i].flag=1;
		else if(stu[i].Vir>=H&&stu[i].Tal<H) stu[i].flag=2;
		else if(stu[i].Vir>=stu[i].Tal) stu[i].flag=3;
		else stu[i].flag=4;
	}
	printf("%d\n",m );
	sort(stu,stu+n,cmp);
	for(int i=0;i<m;i++){
		printf("%s %d %d\n",stu[i].id,stu[i].Vir,stu[i].Tal );
	}
	return 0;
}

	