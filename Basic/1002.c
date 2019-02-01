/*#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
  char c;
  int sum=0;
  while((c=getchar())!='\n') sum+=c-'0';
  char *pinyins[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
  if (sum/100)
  {
    printf("%s ",pinyins[sum/100]);
  }
  if (sum/10)
  {
    printf("%s ",pinyins[sum/10%10]);
  }
 printf("%s\n",pinyins[sum%10]);
 return 0;
}*/
#include<iostream>
#include <vector>
using namespace std;
int main(){
vector<int> v;
  for(int i=1;i<=5;i++){
    v.push_back(i);
  }
  vector<int>::iterator it=v.begin();
  for(int i=0;i<5;i++){
    cout<<*(it+i);
  }
  return 0;
}