#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct node{
	string school;
	int tws,ns;
};
bool cmp(node a,node b){
	if(a.tws!=b.tws) return a.tws>b.tws;
	else if(a.ns!=b.ns) return a.ns<b.ns;
	else return a.school<b.school;
} 
int main(){
	freopen("data.txt","r",stdin);
	int n;
	cin>>n;
	unordered_map<string,int> cnt;
	unordered_map<string,double> sum;
	for(int i=0;i<n;i++){
		string id,school;
		cin>>id;
		double score;
		cin>>score;
		cin>>school;
		for(int j=0;j<school.length();j++){
			school[j]=tolower(school[j]);
		}
		if(id[0]=='B') score=score/1.5;
		else if(id[0]=='T') score=score*1.5;
		sum[school]+=score;
		cnt[school]++;
	}
	vector<node>ans;
	for(auto it =cnt.begin();it!=cnt.end();it++){
		node temp;
		temp.school=it->first;
		temp.tws=sum[it->first];
		temp.ns=cnt[it->first];
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end(),cmp);
	int rank=0,pres=-1;
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		if(pres!=ans[i].tws)rank=i+1;
		pres=ans[i].tws;
		cout<<rank<<" "<<ans[i].school<<" "<<ans[i].tws<<" "<<ans[i].ns<<endl;
	}
	return 0;

}