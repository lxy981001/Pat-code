#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Person{
	char name[20];
	char subject[20];
	int score;
} stu[10010];
bool cmp(Person a,Person b){
	return a.score>b.score;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].subject>>stu[i].score;
	}
	sort(stu,stu+n,cmp);
	int Left,Right;
	cin>>Left>>Right;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(stu[i].score>=Left&&stu[i].score<=Right){
			cout<<stu[i].name<<" "<<stu[i].subject<<endl;
			flag=true;
		}
	}
	if(flag==false){
			cout<<"NONE"<<endl;
	}
	return 0;
}