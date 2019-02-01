#include<iostream>
#include<vector>
using namespace std;
int m,n;
vector<int>level;
void postOrder(int index){
	if(index>=n) return ;
	postOrder(index*2+1);
	postOrder(index*2+2);
	printf("%d%s",level[index],index==0?"\n":" " );
}
int main(){
	cin>>m>>n;
	level.resize(n);
	for(int i=0;i<m;i++){	
		for(int j=0;j<n;j++)cin>>level[j];
		int flag=level[0]>level[1]?1:-1;
		for(int j=0;j<=(n-1)/2;j++){
			int left=j*2+1,right=j*2+2;
			if(flag==1&&(level[j]<level[left]||(right<n&&level[j]<level[right]))) flag=0;
			if(flag==-1&&(level[j]>level[left]||(right<n&&level[j]>level[right]))) flag=0;	
		}
		if(flag==0) printf("Not Heap\n");
		else printf("%s Heap\n",flag==1?"Max":"Min" );
		postOrder(0);
	}
	return 0;
}