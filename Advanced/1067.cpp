#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int pos[maxn];//pos数组用来储存数字对应的位置
int main(){
	int n;
	cin>>n;
	int left=n-1,ans=0,num;//left为除了0不在本位的数字
	for(int i=0;i<n;i++){
		cin>>num;
		pos[num]=i;
		if(num==i&&num!=0){
			left--;
		}
	}
	int k=1;//除了0以外 当前不在本位的数字
	while(left>0){
		if(pos[0]==0){
			while(k<n){
				if(pos[k]!=k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0]!=0){
			swap(pos[0],pos[pos[0]]);//数字0和在pos【0】交换；
			ans++;
			left--;
		}
	}
	cout<<ans<<endl;
	return 0;
}