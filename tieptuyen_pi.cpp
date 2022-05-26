//xap xi pi tiep tuyen
#include<stdio.h>
#include<math.h>
double f(double x){
	return tan(x/4) -1;
	}
double	f1(double x){
	return 0.25*1/pow(cos(x/4),2);
	}

int main(){
	/*B1:
	x = pi => f(x) = tan(x/4) - 1 = 0 
	f'(x) = 1/cos^2(x); f"(x) = (cosx^-2)' = -2cosx^-3.-sinx = 2cosx^3.sinx
	minf'(x).maxf'(x) > 0
	minf"(x).maxf"(x) > 0
	B2:
	f(3.2).f"(3.2) > 0
	Chon x = 3.2
	*/
	double xo = 3.2 ,e;
	printf("Nhap sai so: ");
	scanf("%lf",&e);
	//B3 Dieu kien dung
	double m1 = 1.867871964;
	//B4 Tim xap xi
	double x1= xo - f(xo)/f1(xo);
	double eo = m1*e;
	while(fabs(f(xo))>eo){
		xo = x1;
		x1 = xo - f(xo)/f1(xo);

		}
	printf("pi = %.12lf",x1);
	
	
	
	
	return 0;
}

