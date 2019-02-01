#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=20000000;
struct station{
	double dist,price;
} st[maxn];
bool cmp(station a,station b){
	return a.dist<b.dist;
}
int main(){
	int n;
	double Cmax,D,Davg;
	cin>>Cmax>>D>>Davg>>n;
	for(int i=0;i<n;i++){
		cin>>st[i].price>>st[i].dist;
	}
	st[n].dist=D;//将目的地设置为 距离为D，油价为0的一个结构；
	st[n].price=0;
	sort(st,st+n,cmp);//将数组按距离由小到大排序；
	if(st[0].dist!=0){//如果始发站的距离不为0则表示走不了
		cout<<"The maximum travel distance = 0.00"<<endl;
	}else{
		int now=0;//当前所处加油站编号
		double ans=0,nowtank=0,Max=Cmax*Davg;//ans为花费，nowtank为当前油量，Max为能到达最远距离
		while(now<n){//每次循环将选出下个需要达到的加油站
			int k=-1;//最低油价的油站编号
			double priceMin=INF;
			for(int i=now+1;i<=n&&st[i].dist-st[now].dist<=Max;i++){
				if(st[i].price<priceMin){//如果油价比当前最低油价低
					priceMin=st[i].price;//更新最低油价
					k=i;
					if(priceMin<st[now].price){
						break;//如果找到第一个油价低于当前油价的车站，终端循环
					}
				}
			}
			if(k==-1) break; 
			double need=(st[k].dist-st[now].dist)/Davg;//需要多少油从now到k
			if(priceMin<st[now].price){//如果加油站k的油价低于当前油价
				if(nowtank<need){//如果当前油量小于需要油量
					ans+=(need-nowtank)*st[now].price;//加能够到达k的油
					nowtank=0;
				}else{//油超过需要的油
					nowtank-=need;
				}
			}else{//如果加油站k的油价高于当前油价；
				ans+=(Cmax-nowtank)*st[now].price;//将邮箱加满
				nowtank=Cmax-need;//到达k后剩余油量
			}
			now=k;
		}
		if(now==n){
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
		}else{
			double distnow=st[now].dist+Max;
			cout<<"The maximum travel distance = ";
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<distnow<<endl;
		}
	}
	return 0;
}