#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL convert(string n,LL radix){
	LL sum=0;
	int index=0,temp=0;
	for(auto it=n.rbegin();it!=n.rend();it++){
		temp=isdigit(*it)?*it-'0':*it-'a'+10;
		sum+=temp*pow(radix,index++);
	}
	return sum;
}
LL find_radix(string n,LL num){
	char it=*max_element(n.begin(),n.end());
	LL low=(isdigit(it)?it-'0':it-'a'+10)+1;
	LL high=max(num,low);
	while(low<=high){
		LL mid=(low+high)/2;
		LL t=convert(n,mid);
		if(t<0||t>num) high=mid-1;
		else if(t==num) return mid;
		else low=mid+1;
	}
	return -1;
}
int main(){
	string n1,n2;
	LL tag=0,radix=0,result_radix;
	cin>>n1>>n2>>tag>>radix;
	result_radix=tag==1?find_radix(n2,convert(n1,radix)):find_radix(n1,convert(n2,radix));
	if(result_radix!=-1){
		cout<<result_radix;
	}else{
		cout<<"Impossible";
	}
	return 0;
}