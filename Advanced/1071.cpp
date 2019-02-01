#include<iostream>
#include<string>
#include<map>
using namespace std;
bool check(char c){//判断有没有非规定字符
	if(c>='A'&&c<='Z') return true;
	if(c>='a'&&c<='z') return true;
	if(c>='0'&&c<='9') return true;
	return false;
}
int main(){
	map<string,int> count;//string 对int的映射
	int i=0;//str的下标
	string str;
	getline(cin,str);
	while(i<str.length()){//开始遍历str
		string word;
		while(check(str[i])==true){//在规定字符内
			if(str[i]>='A'&&str[i]<='Z'){//大写转小写
				str[i]+=32;
			}
			word+=str[i];//将这个字符接到word后
			i++;//下标往后移动
		}
		if(word!=""){//word非空，开始映射
			if(count.find(word)==count.end()) count[word]=1;//word不在count里
			else count[word]++;//在count里，数字++；
		}
		while(check(str[i])==false){//如果是非法字符，后移下表
			i++;
		}
	}
	string ans;
	int max=0;
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++){//遍历count
		if(it->second>max){
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max;
	return 0;
}