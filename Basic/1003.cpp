#include<iostream>
#include<string>
using namespace std;
string str;
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>str;
		int size=str.length();
		int numP=0,numT=0,other=0;
		int localP=-1,localT=-1;
		for(int i=0;i<size;i++){
			if(str[i]=='P'){
				numP++;
				localP=i;
			}else if(str[i]=='T'){
				numT++;
				localT=i;
			}else if(str[i]!='A') other++;
		}
		if((numP!=1)||(numT!=1)||(other!=0)||(localT-localP<=1)){
			cout<<"NO"<<endl;
			continue;
		}
		int x=localP,y=localT-localP-1,z=size-localT-1;
		if(z-x*(y-1)==x) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}