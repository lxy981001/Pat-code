#include<cstdio>
struct Poly{
	int exp;
	double coef;
} poly[1001];
double ans[2001];
int main(){
	int n,m;
	int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %lf",&poly[i].exp,&poly[i].coef);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int exp;
		double coef;
		scanf("%d %lf",&exp,&coef);
		for(int j=0;j<n;j++){
			ans[exp+poly[j].exp]+=(coef*poly[j].coef);
		}
	}
	for(int i=0;i<=2000;i++){
		if(ans[i]!=0) count++;
	}
	printf("%d",count );
	for(int i=2000;i>=0;i--){
		if(ans[i]!=0){
			printf(" %d %.1f",i,ans[i] );
		}
	}
	return 0;
}