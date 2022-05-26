//Tim pi voi sai so E cho ruoc
#include<stdio.h>
#include<math.h>

int main(){
	// a = 3; f(a)<0
	// b = 3,2; f(b)>0
	double e, a = 3,b = 3.2;
	double c;
	scanf("%lf",&e);
	while((b-a)>=e){
		 c = (a+b)/2;
		double z = tan(c/4)-1;
		if(z==0){
			goto d;
		}
		if(z>0){
			b = c;
		}
		else{
			a = c;
		}
	}
	d:
	printf("Gia so tri pi la: %.24lf",c);
	return 0;
}
