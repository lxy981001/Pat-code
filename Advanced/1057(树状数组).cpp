#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#define lowbit(i) ((i)&-(i))
using namespace std;
const int maxn=100010;
stack<int>s;
int c[maxn];
void updata(int x,int v){
	for(int i=x;i<maxn;i+=lowbit(i)){
		c[i]+=v;
	}
}
int getmax(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum+=c[i];
	}
	return sum;
}
void PeekMedian(){
	int l=1,r=maxn,mid,k=(s.size()+1)/2;
	while(l<r){
		mid=(l+r)/2;
		if(getmax(mid)>=k) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}

int main(){
	int n,x;
	string cmd;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cmd;
		if(cmd=="Push"){
			cin>>x;
			s.push(x);
			updata(x,1);
		}else if(cmd=="Pop"){
			if(s.empty()) cout<<"Invalid"<<endl;
			else{
				cout<<s.top()<<endl;
				updata(s.top(),-1);
				s.pop();
			}
		}else if(cmd=="PeekMedian"){
			if(s.empty())cout<<"Invalid"<<endl;
			else PeekMedian();
		}
	}
	return 0;
}