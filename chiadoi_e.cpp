//Tim e voi sai so E cho ruoc
#include<stdio.h>
#include<math.h>

int main(){
	// a = 2; f(a)<0
	// b = 3; f(b)>0
	 double e, a = 2,b = 3;
	 double c;
	scanf("%f",&e);
	while((b-a)>=e){
		c = (a+b)/2;
		double z = log(c)-1;
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
	printf("Gia so tri e la: %.12f",c);
	return 0;
}
