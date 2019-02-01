#include<cstdio>
const int Galleon=17*29;
const int Stickle=29;
int main(){
	int a1,b1,c1,a2,b2,c2;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	int price=a1*Galleon+b1*Stickle+c1;
	int money=a2*Galleon+b2*Stickle+c2;
	int change=money-price;
	if(change<0){
		printf("-");
		change=-change;
	}
	printf("%d.%d.%d\n",change/Galleon,change%Galleon/Stickle,change%Stickle );
	return 0;
}