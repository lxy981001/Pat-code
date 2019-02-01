#include<stdio.h>  
#include<math.h>   
int main(){
    int n;
    scanf("%d",&n);
    int m;
    int temp[101]={0};
    int i,j,k=n;
    while (n--){
        scanf("%d",&m);
        temp[m]=1;
    }
    for(i=1;i<=100;i++){
        if(temp[i]){
            for(j=i;j>1;){
                if(j%2) 
                    j=(j*3+1)/2;
                else 
                    j/=2;
                if(j<=100&&temp[j]){
                    temp[j]=0;
                    k--;
                    if(j<i) 
                        break;
                }
            }
        }
    }
    for(i=100;i>=1;i--){
        if(temp[i]==1){
            printf("%d",i);
            k--;
            if(k) printf(" ");
        }
    }
    return 0;
}  
 