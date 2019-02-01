#include<cstdio>
int main(){
	int k;
	scanf("%d",&k);
	char tmp[5]={'S','H','C','D','J'};
	int start[55],end[55],next[55];
	for(int i=1;i<=54;i++){
		start[i]=i;
	}
	for(int i=1;i<=54;i++){
		scanf("%d",&next[i]);
	}
	for(int step=0;step<k;step++){
		for(int i=1;i<=54;i++){
			end[next[i]]=start[i];
		}
		for(int i=1;i<=54;i++){
			start[i]=end[i];
		}
	}
	for(int i=1;i<=54;i++){
		if(i!=1) printf(" ");
		start[i]--;
		printf("%c%d",tmp[start[i]/13],start[i]%13+1 );
	}

	return 0;
}