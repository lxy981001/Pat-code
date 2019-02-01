#include<iostream>
#include<algorithm>
#include<iomanip>
struct mooncake{
	double store;
	double sell;
	double price;
} cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}
using namespace std;
int main(){
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>cake[i].store;
	}
	for(int i=0;i<n;i++){
		cin>>cake[i].sell;
		cake[i].price=cake[i].sell/cake[i].store;
	}
	sort(cake,cake+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++){
		if(cake[i].store<=d){
			d-=cake[i].store;
			ans+=cake[i].sell;
		}else{
			ans+=cake[i].price*d;
			break;
		}
	}
	cout.setf(ios::fixed);
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}