#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
const int table=500010;
struct Node{
	int address,key,next;
	int order;
} node[maxn];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
bool isExist[table];
int main(){
	memset(isExist,false,sizeof(isExist));
	for(int i=0;i<maxn;i++){
		node[i].order=2*maxn;
	}
	int begin,n,address;
	cin>>begin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&address );
		scanf("%d",&node[address].key);
		scanf("%d",&node[address].next);
		node[address].address=address;
	}
	int p=begin;
	int countValid=0,countRemoved=0;
	while(p!=-1){
		if(!isExist[abs(node[p].key)]) {
			isExist[abs(node[p].key)]=true;
			node[p].order=countValid++;
		}else{
			node[p].order=maxn+countRemoved++;
		}
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	int count=countRemoved+countValid;
	for(int i=0;i<count;i++){
		if(i!=countValid-1&&i!=count-1){
			printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address );
		}else{
			printf("%05d %d -1\n",node[i].address,node[i].key);
		}
	}
	return 0;
}	