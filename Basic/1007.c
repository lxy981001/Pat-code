#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int preprime=0;
    int cnt=0;
    for(int i=n;i>1;i--){
        int flag=1;
        for(int j=2;j<=(int)sqrt(i);j++){
            if(i%j==0) {
                flag=0;
                break;
            }
        }
        if(flag==1){
            if(preprime>1&&preprime-i==2){
                cnt++;
            }
            preprime=i;
        }
    }
    printf("%d\n",cnt );
    return 0;
}