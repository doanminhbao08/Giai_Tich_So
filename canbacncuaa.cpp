//Tim so can bac n cua a
#include<stdio.h>
#include<math.h>

int main(){
	// x sao cho z < 0
	// y sao cho z > 0
	double x,y,a,e,c,z;
	int n;
	printf("Nhap gia tri so a: ");
	scanf("%lf",&a);
	printf("\nNhap gia tri so mu n: ");
	scanf("%d",&n);
	printf("\nNhap gia tri sai so cho phep e: ");
	scanf("%lf",&e);
if(a>=1){
	x=0;
	y=a;
	while((y-x)>=e){
		c = (x+y)/2;
		z = pow(c,n)-a;   //z = x^n -a = 0; a thuoc R; n thuoc N*
		if(z==0){
			goto d;
		}
		if(z>0){
			y = c;
		}
		else{
			x = c;
		}
	}
	d:
	printf("Gia so tri can tim la: %.24lf",c);
	}
else if(a>=0 && a<1){
	
	x=0;
	y=1;
	while((y-x)>=e){
		c = (x+y)/2;
		z = pow(c,n)-a;   //z = x^n -a = 0; a thuoc R; n thuoc N*
		if(z==0){
			goto e;
		}
		if(z>0){
			y = c;
		}
		else{
			x = c;
		}
	}
	e:
	printf("Gia so tri can tim la: %.24lf",c);
	
}
else{
		if(n%2==1){
			x=a;
			y=0;
			while((y-x)>=e){
				c = (x+y)/2;
				z = pow(c,n)-a;   //z = x^n -a = 0; a thuoc R; n thuoc N*
				if(z==0){
					goto k;
				}
				if(z>0){
					y = c;
				}
				else{
					x = c;
				}
			}
			k:
			printf("Gia so tri can tim la: %.24lf",c);
		}
		else{
			printf("Khong ton tai");
		}
}
	return 0;
}
	
	
