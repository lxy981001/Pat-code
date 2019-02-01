#include<cstdio>
struct Info{
	char name[100010];
	int yy,mm,dd;
} Left,Right,Oldest,Youngest,temp;
bool Less(Info a,Info b){
	if(a.yy!=b.yy) return a.yy<=b.yy;
	else if(a.mm!=b.mm) return a.mm<=b.mm;
	else return a.dd<=b.dd;
}
bool More(Info a,Info b){
	if(a.yy!=b.yy) return a.yy>=b.yy;
	else if(a.mm!=b.mm) return a.mm>=b.mm;
	else return a.dd>=b.dd;
}
void init(){
	Left.yy=Youngest.yy=1814;
	Right.yy=Oldest.yy=2014;
	Left.mm=Youngest.mm=Right.mm=Oldest.mm=9;
	Left.dd=Youngest.dd=Right.dd=Oldest.dd=6;
}
int main(){
	init();
	int n,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
		if(Less(temp,Right)&&More(temp,Left)){
			 count++;
			if(Less(temp,Oldest))  Oldest=temp;
			if(More(temp,Youngest)) Youngest=temp;
		}
	}
	if(count==0) printf("0\n");
	else printf("%d %s %s\n", count,Oldest.name,Youngest.name );
	return 0;
}