#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
struct Fraction{
	LL down,up;
}a,b;
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
	}else{
		int d=gcd(abs(result.up),abs(result.down));
		result.up=result.up/d;
		result.down=result.down/d;
	}
	return result;
}
Fraction add(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down+f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}
Fraction minu(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down-f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}
Fraction multi(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}
Fraction divid(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}
void showResult(Fraction r){
	r=reduction(r);
	if(r.up<0) cout<<"(";
	if(r.down==1) cout<<r.up;
	else if(abs(r.up)>r.down){
		cout<<r.up/r.down<<' '<<abs(r.up)%r.down<<'/'<<r.down;
	}else cout<<r.up<<'/'<<r.down;
	if(r.up<0) cout<<")";
}
int main(){
	char c='/';
	cin>>a.up>>c>>a.down>>b.up>>c>>b.down;
	showResult(a);
	cout<<" + ";
	showResult(b);
	cout<<" = ";
	showResult(add(a,b));
	cout<<endl;
	showResult(a);
	cout<<" - ";
	showResult(b);
	cout<<" = ";
	showResult(minu(a,b));
	cout<<endl;
	showResult(a);
	cout<<" * ";
	showResult(b);
	cout<<" = ";
	showResult(multi(a,b));
	cout<<endl;
	showResult(a);
	cout<<" / ";
	showResult(b);
	cout<<" = ";
	if(b.up==0) cout<<"Inf";
	else showResult(divid(a,b));
	return 0;
}