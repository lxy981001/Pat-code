#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int Age[maxn]={0};
struct Person{
	char name[20];
	int age;
	int worth;
} man[maxn],temp[maxn];
bool cmp(Person a,Person b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>man[i].name>>man[i].age>>man[i].worth;
	}
	sort(man,man+n,cmp);
	int tempnum=0;
	for(int i=0;i<n;i++){
		if(Age[man[i].age]<100){
			Age[man[i].age]++;
			temp[tempnum++]=man[i];
		}
	}
	int m,ageL,ageR;
	for(int i=1;i<=k;i++){
		int printman=0;
		cin>>m>>ageL>>ageR;
		cout<<"Case"<<" "<<"#"<<i<<":"<<endl;
		for(int j=0;j<tempnum&&printman<m;j++){
			if(temp[j].age>=ageL&&temp[j].age<=ageR){
				cout<<temp[j].name<<" "<<temp[j].age<<" "<<temp[j].worth<<endl;
				printman++;
			}
		}
		if(printman==0){
				cout<<"None"<<endl;
			}
	}
	return 0;
}