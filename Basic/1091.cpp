#include<iostream>
#include<string>
using namespace std;
int main(){
	int m,a;
	cin>>m;
	while(m--){
		cin>>a;
		int flag=0;
		for(int i=1;i<=9;i++){
			int temp=a*a*i;
			string st=to_string(temp),sa=to_string(a);
			string se=st.substr(st.length()-sa.length());
			if(sa==se){
				cout<<i<<" "<<temp<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"No"<<endl;
	}
	return 0;
}