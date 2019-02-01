#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL p=1e7+19;
const LL MOD=1e9+9;
const LL maxn=1010;
LL powp[maxn],H1[maxn],H2[maxn];
void init(){
	powp[0]=1;
	for(int i=1;i<maxn;i++){
		powp[i]=(powp[i-1]*p)%MOD;
	}
}
void calH(LL H[],string &str){
	H[0]=str[0];
	for(int i=1;i<str.length();i++){
		H[i]=(H[i-1]*p+str[i])%MOD;
	}
}
int calSubH(LL H[],int i,int j){
	if(i==0) return H[j];
	return ((H[j]-H[i-1]*powp[j-i+1])%MOD+MOD)%MOD;
}
int binarySearch(int l,int r,int len,int i,int isEven){
	while(l<r){
		int mid=(l+r)/2;
		int H1L=i-mid+isEven,H1R=i;
		int H2L=len-1-(i+mid),H2R=len-1-(i+isEven);
		int hashL=calSubH(H1,H1L,H1R);
		int hashR=calSubH(H2,H2L,H2R);
		if(hashL!=hashR) r=mid;
		else l=mid+1;
	}
	return l-1;
}
int main(){
	init();
	string str;
	getline(cin,str);
	calH(H1,str);
	reverse(str.begin(),str.end());
	calH(H2,str);
	int ans=0;
	for(int i=0;i<str.length();i++){
		int maxLen=min(i,(int )str.length()-1-i)+1;
		int k=binarySearch(0,maxLen,str.length(),i,0);
		ans=max(ans,k*2+1);
	}
	for(int i=0;i<str.length();i++){
		int maxLen=min(i+1,(int)str.length()-1-i)+1;
		int k=binarySearch(0,maxLen,str.length(),i,1);
		ans=max(ans,k*2);
	}
	cout<<ans;
}