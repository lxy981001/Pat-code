// #include<iostream>
// #include<string>
// using namespace std; 
// bool Symmetric(string &str,int s,int len){
//     int i,j,k;
//     for(i=s;i<len/2+s;i++){
//         if(str[i]!=str[s+len-(i-s)-1]) return false;
//     }
//     return true;
// }
 
 
// int main(){
//     string str;
//     getline(cin,str);
//     int maxlen=1;
//     int i,j,k;
//     for(i=0;i<str.size();i++){
//         for(j=1;j<=str.size()-i;j++){
//             if(Symmetric(str,i,j)&&j>maxlen) maxlen=j;
//         }
//     }
//     cout<<maxlen<<endl;
//     return 0;
// }
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=1010;
string s;
int dp[maxn][maxn];

int main(){ 
    getline(cin,s);
    int len=s.size(),ans=1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }
    for(int L=3;L<len;L++){
        for(int i=0;i+L-1<len;i++){
            int j=i+L-1;
            if(s[i]==s[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}