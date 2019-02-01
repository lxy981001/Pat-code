#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int maxn=1010;
int arr[maxn];
stack<int> st;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	while(k--){
		while(!st.empty()){
			st.pop();
		}
		for(int i=1;i<=n;i++){//读入要判别的序列
			cin>>arr[i];
		}
		int current=1;//栈序列中等待出栈的元素
		bool flag=true;//表示栈合法
		for(int i=1;i<=n;i++){//将1-n入stack
			st.push(i);
			if(st.size()>m){//如果超过stack的capacity，跳出循环
				flag=false;
				break;
			}
			while(!st.empty()&&st.top()==arr[current]){//stack非空，并且栈顶元素是当前位置序列元素
				st.pop();//出栈
				current++;//当前位置后移
			}
		}
		if(st.empty()==true&&flag==true){//栈空且flag==true
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}