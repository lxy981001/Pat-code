#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10010;
struct Person{
	int id;
	int score[10];
	bool flag;
	int totalscore;
	int solve;
} stu[maxn];
bool cmp(Person a,Person b){
	if(a.flag!=b.flag) return a.flag>b.flag;
	else if(a.totalscore!=b.totalscore) return a.totalscore>b.totalscore;
	else if(a.solve!=b.solve) return a.solve>b.solve;
	else return a.id<b.id;
}
int n,m,k;
int grades[10];
void init(){
	for(int i=1;i<=n;i++){
		stu[i].id=i;
		stu[i].totalscore=0;
		stu[i].solve=0;
		stu[i].flag=false;
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
int main(){
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>grades[i];
	}
	int u_id,p_id,score_obtain;
	for(int i=0;i<k;i++){
		cin>>u_id>>p_id>>score_obtain;
		if(score_obtain!=-1){
			stu[u_id].flag=true;
		}
		if(score_obtain==-1&&stu[u_id].score[p_id]==-1){
			stu[u_id].score[p_id]=0;
		}
		if(score_obtain==grades[p_id]&&stu[u_id].score[p_id]<grades[p_id]){
			stu[u_id].solve++;
		}
		if(score_obtain>stu[u_id].score[p_id]){
			stu[u_id].score[p_id]=score_obtain;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(stu[i].score[j]!=-1){
				stu[i].totalscore+=stu[i].score[j];
			}
		}
	}
	sort(stu+1,stu+n+1,cmp);
	int r=1;
	for(int i=1;i<=n&&stu[i].flag==true;i++){
		if(stu[i].totalscore!=stu[i-1].totalscore){
			r=i;
		}
		cout<<r<<" ";
		cout.fill('0');
		cout.width(5);
		cout<<stu[i].id<<" "<<stu[i].totalscore;
		for(int j=1;j<=m;j++){
			if(stu[i].score[j]==-1){
				cout<<" "<<"-";
			}else cout<<" "<<stu[i].score[j];
		}
		cout<<endl;
	}
	return 0;
}