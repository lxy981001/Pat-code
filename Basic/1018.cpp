#include<cstdio>
int Change(char(c));
int main(){
	char tmo[3]={'B','C','J'};
	int n;
	scanf("%d",&n);
	int tmp1[3]={0},tmp2[3]={0};//分别记录甲乙的胜负平的次数
	int cnt1[3]={0},cnt2[3]={0};//cnt1记录甲赢的最多的品种，cnt2记录乙赢的最的品种
	int k1,k2;
	char c1,c2;
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %c",&c1,&c2);
		k1=Change(c1);
		k2=Change(c2);
		if((k1+1)%3==k2){
			tmp1[0]++;
			tmp2[1]++;
			cnt1[k1]++;
		} else if(k1==k2){
			tmp1[2]++;
			tmp2[2]++;

		}else {
			tmp1[1]++;
			tmp2[0]++;
			cnt2[k2]++;
		}
	}
	printf("%d %d %d\n",tmp1[0],tmp1[2],tmp1[1] );
	printf("%d %d %d\n",tmp2[0],tmp2[2],tmp2[1] );
	int id1=0,id2=0;
	for (int i = 0; i < 3; ++i){
		if(cnt1[i]>cnt1[id1]) id1=i;
		if(cnt2[i]>cnt2[id2]) id2=i;
	}
	printf("%c %c",tmo[id1],tmo[id2] );
	return 0;
}
int Change(char(c)){
	if(c=='B') return 0;
	if(c=='C') return 1;
	if(c=='J') return 2;
}