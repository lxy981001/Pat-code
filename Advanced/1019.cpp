#include<cstdio>
bool Judge(int z[],int num){
	for(int i=0;i<num/2;i++){
		if(z[i]!=z[num-1-i])
			return false;
	}
	return true;
}
int main(){
	int n,b;
	scanf("%d %d",&n,&b);
	int ans[50],num=0;
	do{
		ans[num++]=n%b;
		n/=b;
	}while(n!=0);
	bool flag=Judge(ans,num);
	if(flag==true)printf("Yes\n");
	else printf("N\n");
	for(int i=num-1;i>=0;i--){
		printf("%d",ans[i] );
		if(i!=0) printf(" " );
	}
	return 0;
}