// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<algorithm>
// using namespace std;
// int main(){
// 	int n,m,cnt;
// 	double G1=0.0,G2=0.0;
// 	cin>>n>>m;
// 	cnt=n-1;
// 	vector<vector<int> >score(n,vector<int> (n));
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cin>>score[i][j];
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(score[i][j]<0||score[i][j]>m){
// 				cnt--;
// 				score[i][j]=-1;
// 			}
// 		}
// 		sort(score[i].begin()+1,score[i].end());
// 		G2=1.0*score[i][0];
// 		for(int j=n-cnt+1;j<=n-2;j++){
// 			G1+=1.0*score[i][j];
// 		}
// 		int sum=(int )floor((G1/(cnt-2)+G2)/2+0.5);
// 		cout<<sum<<endl;
// 		G1=0;
// 		cnt=n-1;
// 	}
// 	return 0;
// }
#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int g2,g1=0,max=-1,min=m+1,temp,cnt=-2;
		cin>>g2;
		for(int j=0;j<n-1;j++){
			cin>>temp;
			if(temp>=0&&temp<=m){
				if(temp>max) max=temp;
				if(temp<min) min=temp;
				g1+=temp;
				cnt++;
			}
		}
		int sum=(((g1-min-max)*1.0/cnt)+g2)/2+0.5;
		cout<<sum<<endl;
	}
	return 0;
}