#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,cnt=0;
	char a[50],b[50];
	cin>>n;
	double temp,sum=0.0;
	for(int i=0;i<n;i++){
		scanf("%s",a);
		sscanf(a,"%lf",&temp);
		sprintf(b,"%.2f",temp);
		int flag=0;
		for(int j=0;j<strlen(a);j++){
			if(a[j]!=b[j]) flag=1;
		}
		if(flag||temp<-1000||temp>1000){
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		}else{
			sum+=temp;
			cnt++;
		}
	}
	if(cnt==1) {
		printf("The average of 1 number is %.2lf",sum );
	}else if(cnt>1) {
		printf("The average of %d numbers is %.2lf",cnt,sum/cnt );
	}else {
		printf("The average of 0 numbers is Undefined\n");
	}
	return 0;
}