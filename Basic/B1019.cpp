#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn=10010;
bool cmp(int a,int b){
	return a>b;
}
void divide(int a,int b[]){
	for(int i=0;i<4;i++){
		b[i]=a%10;
		a/=10;
	}
}
int summery(int b[]){
	int sum=0;
	for(int i=0;i<4;i++){
		sum=sum*10+b[i];
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	int min,max;
	int num[5];
	while(1){
		divide(n,num);
		sort(num,num+4);
		min=summery(num);
		sort(num,num+4,cmp);
		max=summery(num);
		n=max-min;
		cout<<setw(4)<<setfill('0')<<max<<' ' ;
		cout<<'-'<<' ';
		cout<<setw(4)<<setfill('0')<<min<<' ';
		cout<<'='<<' ';
		cout<<setw(4)<<setfill('0')<<n<<endl;
		if(n==0||n==6174) break;
	}
	return 0;
}