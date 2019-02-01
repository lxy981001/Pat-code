#include <iostream>
#include <string>
using namespace std;
const int maxn=10010;
int hashtable[maxn]={0};
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int team,id,score;
		cin>>team>>id>>score;
		hashtable[team]+=score;
	}
	int k,max=-1;
	for(int i=0;i<maxn;i++){
		if(hashtable[i]>max){
			max=hashtable[i];
			k=i;
		}
	}
	cout<<k<<' '<<max;
	return 0;
}