#include <stdio.h>
#include<string.h>

int isPass(char str[]);
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	char str[100];
	while(n--){
		scanf("%s",str);
		isPass(str);
	}
	return 0;
}
int isPass(char str[]){
	int positionP=0,positionT=0;
	int countP=0,countA=0,countT=0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i]=='P')
		{
			positionP=i;
			countP++;
		}
		else if(str[i]=='T')
		{
			positionT=i;
			countT++;
		}
		else if(str[i]=='A') countA++;
	}
		if (countT>1||countP>1||(positionT-positionP)<=1||
			countA+countP+countT!=strlen(str)||
			(positionP * (positionT - positionP - 1)) != (strlen(str) - positionT - 1 )) 
			printf("NO\n");
		else printf("YES\n");
}
