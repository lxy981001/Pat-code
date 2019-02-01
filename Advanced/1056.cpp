#include<iostream>
#include<queue>
using namespace std;
const int maxn=1010;
struct mice{
	int weight,rank;
} mouse[maxn];//结构体表示mice的排名和重量
int main(){
	int  np,ng,order;
	cin>>np>>ng;
	for(int i=0;i<np;i++){
		cin>>mouse[i].weight;//读入重量
	}
	queue<int> q;//建立一个存序列的队列
	for(int i=0;i<np;i++){//读入规定序列
		cin>>order;//读入序列
		q.push(order);//序列进队
	}
	int temp=np,group;//temp表示老鼠数量，group表示组数
	while(q.size()!=1){//只要队列不止一个元素
		if(temp%ng==0) group=temp/ng;//确定分的组数
		else group=temp/ng+1;
		for(int i=0;i<group;i++){//遍历每一组
			int k=q.front();//假设k为该组的老鼠最大重量
			for(int j=0;j<ng;j++){//对一组里每个老鼠遍历
				if(i*ng+j>=temp) break;//最后一组老鼠数不足ng时，退出循环
				int front=q.front();//队首老鼠的编号
				if(mouse[front].weight>mouse[k].weight){
					k=front;//找出最大重量老鼠
				}
				mouse[front].rank=group+1;//改轮老鼠编号group+1；
				q.pop();//出队这只老鼠
			}
			q.push(k);//入队k
		}
		temp=group;//当前老鼠数为group数
	}
	mouse[q.front()].rank=1;//当q里只有一个时
	for(int i=0;i<np;i++){
		cout<<mouse[i].rank;
		if(i<np-1) cout<<' ';
	}
	return 0;
}