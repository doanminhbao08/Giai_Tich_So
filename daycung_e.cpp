//xap xi e dung day cung
#include<stdio.h>
#include<math.h>
using namespace std;
double f(double x){
	return log(x) -1;
	}

int main(){
	//B1:
	//x = e => f(x) = log(x) - 1 = 0
	double a=2, b=3;
	/* f(a).f(b) < 0
	 minf'(x).maxf'(x) = 1/2.1/3 > 0
	 minf"(x).maxf"(x) = -1/4.-1/9 > 0
	 B2:
	 f2(2).f"(2) = (ln2-1).-1/4 > 0
	 => d = 2;xo = 3
	 */
	double d=a, xo=b,e;
	printf("Nhap sai so: ");
	scanf("%lf",&e);
	
	//B3 Dieu kien dung
	double M1 = 0.5,m1 = 0.333333333333,c = f(d);// M1 = max |f'(x)| = 1/2
	/* m1 = min |f'(x)| = 1/3
	Eo = Em1/(M1-m1) => xn - x(n-1) <= Eo(M1-m1)/m1
	B4 Tim xap xi*/
	double x1= xo - f(xo)*(xo-d)/(f(xo)-c);
	
	while(fabs(x1-xo)> e*m1/(M1-m1)){
		xo = x1;
		x1 = xo - f(xo)*(xo-d)/(f(xo)-c);
	
	
		}
	printf("e = %.12lf",xo);
	
	
	
	
	return 0;
}
