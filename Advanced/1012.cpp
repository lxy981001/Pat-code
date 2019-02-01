#include <iostream>
#include<algorithm>
#include<cstring>
#include <cmath>
using namespace std;
struct Node{
	int id;
	int score[4];
} stu[2010];
int now;
int Rank[10000000][4]={0};
char course[4]={'A','C','M','E'};
bool cmp(Node a,Node b){
	return a.score[now]>b.score[now];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].score[1]>>stu[i].score[2]>>stu[i].score[3];
		stu[i].score[0]=round((stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0)+0.5;
	}
	for(now=0;now<4;now++){
		sort(stu,stu+n,cmp);
		Rank[stu[0].id][now]=1;
		for(int i=1;i<n;i++){
			if(stu[i].score[now]==stu[i-1].score[now]) Rank[stu[i].id][now]=Rank[stu[i-1].id][now];
			else Rank[stu[i].id][now]=i+1;
		}
	}
	int check;
	for(int i=0;i<m;i++){
		cin>>check;
		if(Rank[check][0]==0) 
			cout<<"N/A"<<endl;
		else {
			int k=0;
			for(int j=0;j<4;j++){
				if(Rank[check][j]<Rank[check][k]){
					k=j;
				}
			}
			cout<<Rank[check][k]<<' '<<course[k]<<endl;
		}
	}
	return 0;
}