#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id,dist;
}stu[10010];
bool cmp(node a,node b){
	return a.dist<b.dist;
}
int main(){
	int n;
	cin>>n;
	int x ,y;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>x>>y;
		stu[i].dist=(x-0)*(x-0)+(y-0)*(y-0);
	}
	sort(stu,stu+n,cmp);
	printf("%04d %04d\n",stu[0].id,stu[n-1].id );
	return 0;
}