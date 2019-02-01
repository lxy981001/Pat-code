#include<cstdio>
#include<iostream>
#include<cstring>
struct Time{
	char ID[20];
	int hh,mm,ss;
}temp,ans1,ans2;//ans1存最早签到时间，ans2存最晚签退时间
bool more(Time a, Time b){
	if(a.hh!=b.hh) return a.hh>b.hh;
	if(a.mm!=b.mm) return a.mm>b.mm;
	else return a.ss>b.ss;
}
int main(){
	int n;
	scanf("%d",&n);
	ans1.hh=24,ans1.mm=60,ans1.ss=60;//最早签到时间设为最大
	ans2.hh=0,ans2.mm=0,ans2.ss=0;//最晚签退时间设为最小
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d",temp.ID,&temp.hh,&temp.mm,&temp.ss);
		if(more(temp,ans1)==false) ans1=temp;
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(more(temp,ans2)==true) ans2=temp;
	}
	printf("%s %s\n",ans1.ID,ans2.ID );
	return 0;
}