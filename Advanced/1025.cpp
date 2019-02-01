#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Rank{
	char id[310];
	int score;
	int localnum;
	int localrank;
} stu[30010];
bool cmp(Rank a,Rank b){
	if(a.score!=b.score) return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,k;
	int num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>stu[num].id>>stu[num].score;
			stu[num].localnum=i;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].localrank=1;
		for(int j=num-k+1;j<num;j++){
			if(stu[j].score==stu[j-1].score){
				stu[j].localrank=stu[j-1].localrank;
			}else stu[j].localrank=j+1-num+k;
		}
	}
	cout<<num<<endl;
	sort(stu,stu+num,cmp);
	int r=1;
	for(int i=0;i<num;i++){
		if(stu[i].score!=stu[i-1].score){
			r=i+1;
		}
		cout<<stu[i].id<<" "<<r<<" "<<stu[i].localnum<<" "<<stu[i].localrank<<endl;
	}
	return 0;
}