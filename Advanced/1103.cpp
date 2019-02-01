#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,p,maxFcasum=-1;
vector<int > fac,ans,temp;//temp为临时存下，
int power(int x){//求X的p次方
	int ans=1;
	for(int i=0;i<p;i++){
		ans*=x;
	}
	return ans;
}
void init(){//预处理fac数组，0也存进去
	int i=0,temp=0;
	while(temp<=n){//将所有不超过n的temp存进fac；
		fac.push_back(temp);
		temp=power(++i);//注意这里必须++i；
	}
}
void DFS(int index,int nowk,int sum,int Facsum){//开始dfs
	if(sum==n&&nowk==k){
		if(Facsum>maxFcasum){
			ans=temp;
			maxFcasum=Facsum;
		}
		return;
	}
	if(sum>n||nowk>k) return;
	if(index-1>=0){
		temp.push_back(index);//底数index加入临时序列
		DFS(index,nowk+1,sum+fac[index],Facsum+index);//选的分支
		temp.pop_back();//选分支结束后，弹出这个数
		DFS(index-1,nowk,sum,Facsum);//不选的分支
	}
}
int main(){
	cin>>n>>k>>p;
	init();//预处理
	DFS(fac.size()-1,0,0,0);//倒着遍历
	if(maxFcasum==-1) cout<<"Impossible"<<endl;
	else{
		cout<<n<<' '<<"="<<' '<<ans[0]<<'^'<<p;
		for(int i=1;i<ans.size();i++){
			cout<<' '<<'+'<<' '<<ans[i]<<'^'<<p;
		}
	}
	return 0;
}