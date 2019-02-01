#include<cstdio>
#define CLK_TCK 100
int main(){
	int C1,C2;
	scanf("%d %d",&C1,&C2);
	int sum=C2-C1;
	if(sum%100>=50) sum=sum/CLK_TCK+1;
	else sum/=100;
	printf("%02d:%02d:%02d\n",sum/3600,sum%3600/60,sum%60 );
	return 0;
}