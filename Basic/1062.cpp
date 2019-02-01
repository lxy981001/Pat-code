#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){
    return !b?a:gcd(b,a%b);
}

int main(){
  int n1, m1, n2, m2, k;
  scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
  double s1 = (double)n1 * (double)k / (double)m1;
  double s2 = (double)n2 * (double)k / (double)m2;
  if (s1 > s2) swap(s1,s2);
  vector<int> p;
  for (int i = (int)s1 + 1; i < s2; ++i){
    if (gcd(i, k) == 1)
      p.push_back(i);
  }
  for (int i = 0; i < p.size(); ++i){
    cout << p[i] << '/' << k;
    if (i != p.size() - 1)
      cout << ' ';
  }
  return 0;
}

