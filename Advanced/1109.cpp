#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	string name;
	int height;
};
bool cmp(node a,node b){
	if(a.height!=b.height) return a.height>b.height;
	else return a.name<b.name;
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<node>stu(n);
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].height;
	}
	sort(stu.begin(),stu.end(),cmp);
	int row=k,t=0;
	int m;
	while(row){
		if(row==k){
			m=(n-n/k*k)+n/k;
		}else {
			m=n/k;
		}
		vector<string>stemp(m);
		stemp[m/2]=stu[t].name;
		int j=m/2-1;
		for(int i=t+1;i<t+m;i+=2){
			stemp[j--]=stu[i].name;
		}
		j=m/2+1;
		for(int i=t+2;i<t+m;i+=2){
			stemp[j++]=stu[i].name;
		}
		cout<<stemp[0];
		for(int i=1;i<m;i++){
			cout<<" "<<stemp[i];
		}
		cout<<endl;
		t+=m;
		row--;
	}
	return 0;
}