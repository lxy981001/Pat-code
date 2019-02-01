#include<iostream>
#include<string>
using namespace std;
int n;
string deal(string s,int& e){
	int k=0;//s的下标
	while(s.length()>0&&s[0]=='0'){//除去先导0，此为0.000的情况
		s.erase(s.begin());
	}
	if(s[0]=='.'){//去小数点
		s.erase(s.begin());
		while(s.length()>0&&s[0]=='0'){//去小数点后面的0，并使e--
			s.erase(s.begin());
			e--;
		}
	}else{//123.xxxx的情况
		while(k<s.length()&&s[k]!='.'){//找小数点，到小数点之前使e++；
			k++;
			e++;
		}
		if(k<s.length()){//去小数点
			s.erase(s.begin()+k);
		}
	}
	if(s.length()==0){//当除去先导0后length为0，说明这个数是0；
		e=0;
	}
	int num=0;
	k=0;
	string res;
	while(num<n){//只要精度没到n
		if(k<s.length()) res+=s[k++]; //只要还有数字，数字加到res末尾
		else res+='0';//否则末尾+0；
		num++;
	}
	return res;
}
int main(){
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2){
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	}else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}