#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int =1;
	while(n--){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		long long sum=a+b;
		bool flag;
		if(a>0&&b>0&&sum<0) flag=true;
		else if(a<0&&b<0&&sum>=0) flag=false;
		else if(sum>c) flag=true;
		else flag=false;
		if(flag==true) printf("Case #%d: true\n",cnt++ );
		else printf("Case #%d: false\n",cnt++ );
	}
	return 0;
}