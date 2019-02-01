#include<cstdio>
int main(){
	int n;
	int a1,a2,b1,b2;
	int cnt1=0;
	int cnt2=0;
	scanf("%d",&n);
	while(n!=0){
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if(a1+b1==a2&&a1+b1!=b2) cnt2++;
		if(a1+b1==b2&&a1+b1!=a2) cnt1++;
		if(a1+b1==a2+b2||a1+b1!=a2+b2){
			cnt1=cnt1;
			cnt2=cnt2;
		}
		n--;
	}
	printf("%d %d\n",cnt1,cnt2 );
	return 0;
}