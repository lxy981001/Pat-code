// #include<iostream>
// #include<cmath>
// using namespace std;
// int main(){
// 	double r1,p1,r2,p2;
// 	cin>>r1>>p1>>r2>>p2;
// 	double A=(r1*r2)*cos(p1+p2);
// 	double B=(r1*r2)*sin(p1+p2);
// 	if(A+0.005>=0&&A<0) printf("0.00");
// 	else printf("%.2f",A);
// 	if(B>=0) printf("+%.2fi\n",B );
// 	else if(B+0.005>=0&&B<0) printf("+0.00i");
// 	else printf("%.2fi",B );
// 	return 0;
// }



#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double r1,p1,r2,p2;
	cin>>r1>>p1>>r2>>p2;
	double A=(r1*r2)*cos(p1+p2);
	double B=(r1*r2)*sin(p1+p2);
	if(abs(A)<0.01) A=0.00;
	if(abs(B)<0.01) B=0.00;
	if(B<0) printf("%.2lf-%.2lfi", A, abs(B));
	else printf("%.2lf+%.2lfi", A, B);
	return 0;
}