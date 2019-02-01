#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct NODE{
	int address,data,next;
	bool flag;
} node[maxn];

int main(){	
	for(int i=0;i<maxn;i++){
		node[i].flag=false;
	}
	int s1,s2,n;
	cin>>s1>>s2>>n;
	int address,next;
	char data;
	for(int i=0;i<n;i++){
		cin>>address>>data>>next;
		node[address].address=address;
		node[address].data=data;
		node[address].next=next;
	}
	int p;
	for(p=s1;p!=-1;p=node[p].next){
		node[p].flag=true;
	}
	for(p=s2;p!=-1;p=node[p].next){
		if(node[p].flag==true) break;
	}
	if(p!=-1){
		printf("%05d\n", node[p].address);
	}else{
		printf("-1\n");
	}
	return 0;
}