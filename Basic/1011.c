#include<stdio.h>
int main(){
  int n;
  scanf("%d\n",&n);
  long long a,b,c;
  for(int i=1;i<=n;i++){
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("Case #%d: ",i );
    if(a+b>c) printf("true\n");
    else printf("false\n");
  }
  return 0;
}