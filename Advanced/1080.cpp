#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct peo{
	int id,gi,ge,fi,rank;
	vector<int> choice;
};
bool cmp1(peo& a,peo& b){
	if(a.fi!=b.fi)return a.fi>b.fi;
	return a.ge>b.ge;
}
bool cmp2(peo& a,peo& b){
	return a.id<b.id;
}

int main(){
	int n,m,k,quota[110],cnt[110]={0};
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&quota[i]);
	}
	vector<peo>stu(n),sch[110];
	for(int i=0;i<n;i++){
		scanf("%d%d",&stu[i].ge,&stu[i].gi);
		stu[i].id=i;
		stu[i].fi=stu[i].gi+stu[i].ge;
		stu[i].choice.resize(k);
		for(int j=0;j<k;j++){
			scanf("%d",&stu[i].choice[j]);
		}
	}
	sort(stu.begin(),stu.end(),cmp1);
	stu[0].rank=1;
	for(int i=1;i<n;i++){
		if(stu[i].fi==stu[i-1].fi&&stu[i].ge==stu[i-1].ge) stu[i].rank=stu[i-1].rank;
		else stu[i].rank=i+1;
	}
	// for(int i=0;i<n;i++){
	// 	printf("%d\n", stu[i].rank);
	// }
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int schid=stu[i].choice[j];
			int lastindex=cnt[schid]-1;
			if(cnt[schid]<quota[schid]||stu[i].rank==sch[schid][lastindex].rank){
				cnt[schid]++;
				sch[schid].push_back(stu[i]);
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		sort(sch[i].begin(),sch[i].end(),cmp2);
		for(int j=0;j<cnt[i];j++){
			if(j!=0) printf(" " );
			printf("%d",sch[i][j].id);
		}
		printf("\n");
	}
	return 0;
}