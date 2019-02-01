#include <stdio.h>
#include<string.h>
typedef struct Student
{
	char name[20];
	char subject[20];
	int Data;
}student;
typedef student Ptr;

int main(int argc, char const *argv[])
{
	unsigned n;
	scanf("%d",&n);
	Ptr temp[10000];
	int max=0,min=0;
	for (int i = 0; i <n; i++)
	{
		scanf("%s %s %d\n",temp[i].name,temp[i].subject,&temp[i].Data);
		if(temp[i].Data>temp[max].Data)  max=i;
		if(temp[i].Data<temp[min].Data) min=i;

	}
	printf("%s %s\n%s %s\n",temp[max].name,temp[max].subject,temp[min].name,temp[min].subject );
	return 0;
}

