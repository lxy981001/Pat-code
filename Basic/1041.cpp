#include<cstdio>
struct theNumber{
	long long  ID;
	int Tnum;
	int Enum;
} Info[1010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %d %d",&Info[i].ID,&Info[i].Tnum,&Info[i].Enum);
	}
	int m;
	scanf("%d",&m);
	int c;
	for(int i=0;i<m;i++){
		scanf("%d",&c);
		for(int i=0;i<n;i++){
			if(Info[i].Tnum==c)
				printf("%lld %d\n",Info[i].ID,Info[i].Enum );
		}
	}
	return 0;
}