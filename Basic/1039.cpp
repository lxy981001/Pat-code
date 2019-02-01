/*#include <iostream>
using namespace std;
int main(){
    string a, b;
    cin >> a;
    cin >> b;
    int count = 0;
    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < a.length(); j++) {
            if (b[i] == a[j]) {
                count++;
                a[j]='!';
                break;
        	}
    	}
    }
    if (count == b.length()) {
        cout << "Yes" << " " << a.length() - count;
    } else {
        cout << "No" << " " << b.length() - count;
    }
    return 0;
}
*/
#include<iostream>
#include<string>
using namespace std;
const int maxn=1010;
int hashtable[maxn]={0};
int change(char c){
	if(c>='0'&&c<='9') return c-'0';
    if(c>='a'&&c<='z') return c-'a'+10;
	if(c>='A'&&c<='Z') return c-'A'+36;
}
int main(){
	int count=0;
	string str1,str2;
	cin>>str1>>str2;
	for(int i=0;i<str1.length();i++){
		int pos=change(str1[i]);
		hashtable[pos]++;
	}
	for(int i=0;i<str2.length();i++){
		int pos=change(str2[i]);
		hashtable[pos]--;
		if(hashtable[pos]<0){
			count++;
		}
	}
	if(count>0) cout<<"No"<<' '<<count<<endl;
	else cout<<"Yes"<<' '<<str1.length()-str2.length()<<endl;
	return 0;
}

