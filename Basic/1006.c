#include<stdio.h>
int main(){
  int n;
  int i;
  scanf("%d",&n);
  int a,b,c;
  a=n/100;
  b=(n%100)/10;
  c=n%10;
  for(i=0;i<a;i++) printf("B");
  for(i=0;i<b;i++) printf("S");
  for(i=1;i<=c;i++)printf("%d",i);
  return 0;
}