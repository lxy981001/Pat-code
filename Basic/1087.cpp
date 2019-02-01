#include <iostream>
#include<set>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<int>st;
	for(int i=1;i<=n;i++){
		int sum=i/2+i/3+i/5;
		st.insert(sum);
	}
	cout<<st.size();
	return 0;
}