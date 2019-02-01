#include<cstdio>
#include<algorithm>
using namespace std ;
const int MAXN=100005;
int main(){
	int n,a,b;
	scanf("%d",&n);
	int tmp[MAXN],dist[MAXN];
	int m,cnt,sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp[i]);
		sum+=tmp[i];
		dist[i]=sum;
	}
	scanf("%d",&m);
	for(int step=1;step<=m;step++){
		scanf("%d %d",&a,&b);
		if(a>b) swap(a,b);
		cnt=dist[b-1]-dist[a-1];
		printf("%d\n",min(cnt,sum-cnt) );
	}

	return 0;
}		