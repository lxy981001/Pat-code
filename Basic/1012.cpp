#include<cstdio>
int main(){
	int cnt[5]={0};
	int ans[5]={0};
	int n,tmp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp%5==0){
			if(tmp%2==0){
				ans[0]+=tmp;
				cnt[0]++;
			}
		}
		if(tmp%5==1){
			if(cnt[1]%2==0) ans[1]+=tmp;
			else ans[1]-=tmp;
			cnt[1]++;
		}
		if(tmp%5==2) cnt[2]++;
		if(tmp%5==3){
			ans[3]+=tmp;
			cnt[3]++;
		}
		if(tmp%5==4){
			int max=ans[0];
			if(tmp>max) max=tmp; ans[4]=max;
			cnt[4]++;
		}
	}
	if(cnt[0]==0) printf("N ");
	else printf("%d ",ans[0] );
	if(cnt[1]==0) printf("N ");
	else printf("%d ",ans[1] );
	if(cnt[2]==0) printf("N " );
	else printf("%d ",cnt[2] );
	if(cnt[3]==0) printf("N ");
	else printf("%.1f ",(double)ans[3]/cnt[3] );
	if(cnt[4]==0) printf("N");
	else printf("%d",ans[4] );
	return 0;
}