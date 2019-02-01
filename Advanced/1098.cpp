#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=110;
int origin[maxn],tempori[maxn],changed[maxn];
int n;
bool isSame(int a[],int b[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
bool showArray(int a[]){
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)cout<<" ";
	}
	cout<<endl;
}
bool insertsort(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(i!=2&&isSame(tempori,changed)){
			flag=true;
		}
		sort(tempori,tempori+i+1);
		if(flag==true){
			return true;
		}
	}
	return false;
}
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&tempori[j+1]>tempori[j]){
			j=j+1;
		}
		if(tempori[j]>tempori[i]){
			swap(tempori[j],tempori[i]);
			i=j;
			j=i*2;
		}else break;
	}
}
void heapsort(){
	bool flag=false;
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
	for(int i=n;i>1;i--){
		if(i!=n&&isSame(tempori,changed)){
			flag=true;
		}
		swap(tempori[i],tempori[1]);
		downAdjust(1,i-1);
		if(flag==true){
			showArray(tempori);
			return;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>origin[i];
		tempori[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		cin>>changed[i];
	}
	if(insertsort()){
		cout<<"Insertion Sort"<<endl;
		showArray(tempori);
	}else{
		cout<<"Heap Sort"<<endl;
		for(int i=1;i<=n;i++){
			tempori[i]=origin[i];
		}
		heapsort();
	}
	return 0;
}