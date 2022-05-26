// f(x) = x^5 + 25x - 17 = 0 => x = (17-x^5)/25
// f'(x) = -x^4/5 =>    -1/5 <= f'(x) <= 0 => q = 0.2
//xap xi pi tiep tuyen
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

double P(double x){
	return (-pow(x,5) + 17)/25;
	}

int main(){
	/*nghiem cua phuong trinh nam trong khoang (0,1) => Chon xo = 0.5;
	*/
	double xo = 0.5,q = 0.2,e;
	printf("Hay nhap sai so e: ");
	scanf("%lf",&e);
	double eo = (1-q)/q*e;
	double x1 = P(xo);
	while(fabs(x1-xo)>eo){
		xo = x1;
		x1 = P(xo);
		}
	printf("Nghiem cua phuong trinh la %.12lf",x1);
	return 0;
	}

