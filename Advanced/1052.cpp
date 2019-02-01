#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct NODE{
	int address,data,next;
	bool flag;
} node[maxn];
bool cmp(NODE a,NODE b){
	if(a.flag==false||b.flag==false){
		return a.flag>b.flag;
	}else{
		return a.data<b.data;
	}
}
int main(){
	for(int i=0;i<maxn;i++){
		node[i].flag=false;
	}
	int n,begin,address;
	cin>>n>>begin;	
	for(int i=0;i<n;i++){
		cin>>address;
		cin>>node[address].data>>node[address].next;
		node[address].address=address;
	}
	int count=0,p=begin;
	while(p!=-1){
		node[p].flag=true;
		count++;
		p=node[p].next;
	}
	if(count==0){
		cout<<"0 -1";
	}else{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",count, node[0].address );
		//cout<<count<<' '<<setw(5)<<setfill('0')<<node[0].address<<endl;
		for(int i=0;i<count;i++){
			if(i!=count-1){
				printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address );
				// cout<<setw(5)<<setfill('0')<<node[i].address<<' ';
				// cout<<node[i].data<<' ';
				// cout<<setw(5)<<setfill('0')<<node[i+1].address<<endl;
			}else{
				printf("%05d %d -1\n",node[i].address,node[i].data );
				// cout<<setw(5)<<setfill('0')<<node[i].address<<' ';
				// cout<<node[i].data<<' ';
				// cout<<"-1"<<endl;
			}
		}
	}
	return 0;
}