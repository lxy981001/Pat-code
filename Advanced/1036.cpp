#include <cstdio>
struct Grade{
	char name[15];
	char subject[15];
	int score;
} M,F,temp;
void inti(){
	M.score=101;
	F.score=-1;
}
int main(){
	inti();
	char gender;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",temp.name,&gender,temp.subject,&temp.score);
		if(gender=='M'&&temp.score<M.score) M=temp;
		if(gender=='F'&&temp.score>F.score) F=temp; 
	}
	if(F.score==-1) printf("Absent\n" );
	else printf("%s %s\n",F.name,F.subject );
	if(M.score==101) printf("Absent\n");
	else printf("%s %s\n",M.name,M.subject );
	if(F.score==-1||M.score==101) printf("NA\n");
	else printf("%d\n",F.score-M.score );
	return 0;
}