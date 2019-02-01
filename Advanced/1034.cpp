#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn=2010;
const int INF=1000000000;
int n,k,numPerson=0;
bool vis[maxn]={false};
int G[maxn][maxn]={0},weight[maxn]={0};
map<string,int>strToInt,Gang;
map<int,string>intToString;
void DFS(int nowVist,int &head,int &numMember,int &totalValue){
	numMember++;
	vis[nowVist]=true;
	if(weight[nowVist]>weight[head]){
		head=nowVist;
	}
	for(int i=0;i<numPerson;i++){
		if(G[nowVist][i]>0){
			totalValue+=G[nowVist][i];
			G[nowVist][i]=G[i][nowVist]=0;
			if(vis[i]==false){
				DFS(i,head,numMember,totalValue);
			}
		}
	}
}
void DFSTravel(){
	for(int i=0;i<numPerson;i++){
		if(vis[i]==false){
			int head=i,numMember=0,totalValue=0;
			DFS(i,head,numMember,totalValue);
			if(numMember>2&&totalValue>k){
				Gang[intToString[head]]=numMember;
			}
		}
	}
}
int change(string str){
	if(strToInt.find(str)!=strToInt.end()) {
		return strToInt[str];
	}
	else{
		strToInt[str]=numPerson;
		intToString[numPerson]=str;
		//numPerson++;
		return numPerson++;
	}
}

int main(){
	int w;
	string str1,str2;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>str1>>str2>>w;
		int id1=change(str1);
		int id2=change(str2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	DFSTravel();
	cout<<Gang.size()<<endl;
	for(auto it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}	
