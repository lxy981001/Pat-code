#include<iostream>
#include<vector>
using namespace std;
bool flag=false;
vector<int> pre,in;
void postOrder(int preL,int inL,int inR){
	if(inL>inR||flag==true) return;
	int i=inL;
	while(in[i]!=pre[preL]) i++;
	postOrder(preL+1,inL,i-1);
	postOrder(preL+i+1-inL,i+1,inR);
	if(flag==false) {
		cout<<in[i];
		flag=true;
	}
}	
int main(){
	int n;
	cin>>n;
	pre.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++){ 
		cin>>pre[i];
	}
	for(int i=0;i<n;i++) {
		cin>>in[i];
	}
	postOrder(0,0,n-1);
	return 0;
}