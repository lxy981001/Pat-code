#include<iostream>
#include <cstring>
#include<algorithm>
using namespace std;
struct List{
	int id;
	char name[10];
	int score;
}	stu[100010];
bool cmp1(List a,List b){
	return a.id<b.id;
}
bool cmp2(List a,List b){
	int s=strcmp(a.name,b.name);
	if(s!=0) return s<0;
	else return a.id<b.id;
}
bool cmp3(List a,List b){
	if(a.score!=b.score) return a.score<b.score;
	else return a.id<b.id;
}
int main(){
	int n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].name>>stu[i].score;
	}
	if(c==1) sort(stu,stu+n,cmp1);
	if(c==2) sort(stu,stu+n,cmp2);
	if(c==3) sort(stu,stu+n,cmp3);
	for(int i=0;i<n;i++){
		cout.fill('0');
		cout.width(6);
		cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
	}
	return 0;
}
