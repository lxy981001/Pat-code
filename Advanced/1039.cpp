#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=40010;
const int M=26*26*26*11;
vector<int > selectcourse[M];
int getid(char s[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+s[i]-'A';
	}
	id=id*10+s[3]-'0';
	return id;
}
int main(){
	int n,k;
	char name[5];
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		int course,x;
		scanf("%d %d",&course,&x);
		for(int j=0;j<x;j++){
			scanf("%s",name);
			int id=getid(name);
			selectcourse[id].push_back(course);
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",name);
		int id=getid(name);
		sort(selectcourse[id].begin(),selectcourse[id].end());
		printf("%s %ld",name,selectcourse[id].size() );
		for(int j=0;j<selectcourse[id].size();j++){
			printf(" %d",selectcourse[id][j]);
		}
		cout<<endl;
	}
	return 0;
}