#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	string s1,s2,s3,s4;
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);
	getline(cin,s4);
	int len1=s1.size();
	int len2=s2.size();
	int len3=s3.size();
	int len4=s4.size();
	int i;
	for(i=0;i<len1&&i<len2;i++){
		if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'){
			printf("%s ",week[s1[i]-'A'] );
			break;
		}
	}
	for(i++;i<len1&&i<len2;i++){
		if(s1[i]==s2[i]){
			if(s1[i]>='0'&&s1[i]<='9'){
				printf("%02d:",s1[i]-'0' );
				break;
			}else if(s1[i]>='A'&&s1[i]<='N'){
				printf("%02d:",s1[i]-'A'+10 );
				break;
			}
		}
	}
	for(i=0;i<len3&&i<len4;i++){
		if(s3[i]==s4[i]){
			if((s3[i]>='A'&&s4[i]<='Z')||(s3[i]>='a'&&s4[i]<='z')){
				//cout<<setw(2)<<setfill('0')<<i<<endl;
				printf("%02d",i);
				break;
			}
		}
	}
	return 0;
}