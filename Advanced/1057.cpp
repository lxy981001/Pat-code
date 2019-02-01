#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int sqrN=316;
int table[maxn];
int block[sqrN];
stack<int > st;
void peekMedian(int k){
	int sum=0;
	int i=0;
	while(sum+block[i]<k){
		sum+=block[i++];
	}
	int num=i*sqrN;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	cout<<num<<endl;
}
void Push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}
void Pop(){
	int x=st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	cout<<x<<endl;
}

int main(){
	int x,query;
	memset(block,0,sizeof(block));
	memset(table,0,sizeof(table));
	string cmd;
	cin>>query;
	for(int i=0;i<query;i++){
		cin>>cmd;
		if(cmd=="Push"){
			cin>>x;
			Push(x);
		}else if(cmd=="Pop"){
			if(st.empty()==true){
				cout<<"Invalid"<<endl;
			}else{
				Pop();
			}
		}else{
			if(st.empty()==true){
				cout<<"Invalid"<<endl;
			}else{
				int k=st.size();
				if(k%2==1) k=(k+1)/2;
				else k=k/2;
				peekMedian(k);
			}
		}
	}
	return 0;
}
