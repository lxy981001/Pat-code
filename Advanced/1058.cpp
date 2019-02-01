#include<cstdio>
const int Galleon=17*29;
const int Stickle=29;
int main(){
	long long  a1,b1,c1,a2,b2,c2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&a1,&b1,&c1,&a2,&b2,&c2);
	long price=a1*Galleon+b1*Stickle+c1;
	long money=a2*Galleon+b2*Stickle+c2;
	long change=money+price;
	
	printf("%lld.%lld.%lld\n",change/Galleon,change%Galleon/Stickle,change%Stickle );
	return 0;
}