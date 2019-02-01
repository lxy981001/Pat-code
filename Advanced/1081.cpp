#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
char c='/';
struct Fraction{
	LL up,down;
} ;
LL gcd(LL a,LL b){
	return !b?a:gcd(b,a%b);
}
Fraction reduction(Fraction result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1;
	}
	else{
		int d=gcd(abs(result.up),abs(result.down));
		result.up/=d;
		result.down/=d;
	}
	return result;
}
Fraction add(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down+f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}
void showResult(Fraction r){
	reduction(r);
	if(r.down==1) cout<<r.up<<endl;
	else if(abs(r.up)>r.down){
		cout<<(r.up/r.down)<<' '<<abs(r.up)%r.down<<'/'<<r.down<<endl;
	}else{
		cout<<r.up<<c<<r.down;
	}
}
int main(){
	int n;
	cin>>n;
	Fraction num,sum;
	sum.up=0,sum.down=1;
	for(int i=0;i<n;i++){
		cin>>num.up>>c>>num.down;
		sum=add(sum,num);
	}
	showResult(sum);
	return 0;
}