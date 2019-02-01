#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,d,k;
	double e,temp;
	int maybe=0,must=0;
	cin>>n>>e>>d;
	for(int i=0;i<n;i++){
		cin>>k;
		int sum=0;
		for(int j=0;j<k;j++){
			cin>>temp;
			if(temp<e) sum++;
		}
		if(sum>k/2&&k>d){
			must++;
		}else if(sum>k/2&&k<=d){
			maybe++;
		}
	}
	double ma=(double)maybe/n*100;
	double mb=(double)must/n*100;
	printf("%.1f%% %.1f%%\n", ma,mb);
	return 0;
}