//xap xi pi dung day cung
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
double f(double x){
	return tan(x/4) -1;
	}
	/// 
int main(){
	//B1:
	//x = pi => f(x) = tan(x/4) - 1 = 0
	double a=3, b=3.2;
	/* f(a).f(b) < 0
	f'(x) = 1/cos^2(x); f"(x) = (cosx^-2)' = -2cosx^-3.-sinx = 2cosx^3.sinx
	minf'(x).maxf'(x) > 0
	minf"(x).maxf"(x)  > 0
	B2:
	f(3).f"(3) < 0
	d = 3.2; xo = 3;*/
	double d=b, xo=a,e;
	printf("Nhap sai so: ");
	scanf("%lf",&e);
	//B3 Dieu kien dung
	double m1 = 1.867871964,M1 = 2.060155558,c = f(d);
	//eo = e.m1/(M1-m1) => xn - x(n-1) <= eo(M1-m1)/m1
	//B4 Tim xap xi
	double x1= xo - f(xo)*(xo-d)/(f(xo)-c);
	
	while(fabs(x1-xo)> e*m1/(M1-m1)){
		xo = x1;
		x1 = xo - f(xo)*(xo-d)/(f(xo)-c);
			printf("e = %.12lf\n",xo);
		}
	printf("e = %.12lf",xo);
	
	
	
	
	return 0;
}
