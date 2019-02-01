
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int l1=a.length();
    int l2=b.length();
    int Max=max(l1,l2);
    int Min=min(l1,l2);
    string s="";
    if(l1<l2){
        for(int i=0; i<l2-l1; i++){
            a='0'+a;
        }
    }
    else{
        for(int i=0; i<l1-l2; i++){
            b='0'+b;
        }
    }
    string t="0123456789JQK";
    for(int j=Max-1; j>=0; j--){
        int loc2=Max-j;
        if(loc2%2==1){
            s=t[(a[j]-'0'+b[j]-'0')%13]+s;
        }
        if(loc2%2==0){
            s=t[((b[j]-'0')-(a[j]-'0')+10)%10]+s;
        }
 
    }
    cout<<s;
    return 0;
}