#include<iostream>
const int maxk=1111;
double a[maxk]={};
int main(){
	int e,m,count=0;
	double c;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %lf",&e,&c );
		a[e]+=c;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %lf",&e,&c);
		a[e]+=c;
	}
	for(int i=0;i<maxk;i++){
		if(a[i]!=0) count ++;
	}
	printf("%d", count );
	for(int i=maxk;i>=0;i--){
		if(a[i]!=0) printf(" %d %.1f",i,a[i]);
	}
	return 0;
}
