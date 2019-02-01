#include<iostream>
#include<map>
#include<string>
using namespace std;
string unitDigit[13]={"tret","jan","feb","mar", "apr", "may", "jun", "jly", "aug"
, "sep", "oct", "nov", "dec"};
string tenDigit[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo"
, "syy", "lok", "mer", "jou"};
std::map<string, int> strTonum;
string numTostr[170];
void init(){//打表
	for(int i=0;i<13;i++){//先分为两种情况，一：十位为0，个位不为0；二：十为不为0，个位为0；
		numTostr[i]=unitDigit[i];//十位为0，个位为 0～12
		strTonum[unitDigit[i]]=i;
		numTostr[13*i]=tenDigit[i];//十位为0～12，个位为0；
		strTonum[tenDigit[i]]=i*13;
	}
	//个位十位都不为0；
	for(int i=1;i<13;i++){//十位
		for(int j=1;j<13;j++){//个位
			string str=tenDigit[i]+" "+unitDigit[j];
			numTostr[i*13+j]=str;
			strTonum[str]=13*i+j;
		}
	}
}
int main(){
	init();
	int n;
	scanf("%d%*c",&n);//查询个数
	while(n--){
		string str;
		getline(cin,str);查询的数
		if(str[0]>='0'&&str[0]<='9'){//如果查询的是数字
			int num=0;//num为numtostr的下标
			for(int i=0;i<str.length();i++){
				num=num*10+(str[i]-'0');
			}
			cout<<numTostr[num]<<endl;//数字->火星文
		}
		else{
			cout<<strTonum[str]<<endl;//火星文->数字；
		}
	}
	return 0;
}