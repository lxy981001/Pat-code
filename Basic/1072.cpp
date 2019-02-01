#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m,k,cnt1=0,cnt2=0,temp;
	bool forbid[10000]={false};
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		forbid[temp]=true;
	}
	for(int i=0;i<n;i++){
		bool flag=false;
		char name[10];
		scanf("%s %d",name,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&temp);
			if(forbid[temp]){
				if(!flag){
					printf("%s:", name);
					flag=true;
				}
				cnt2++;
				printf(" %04d",temp );
			}
		}

		if(flag){
		 printf("\n");
		 cnt1++;
		}
	}
	printf("%d %d\n",cnt1,cnt2 );
	return 0;
}
