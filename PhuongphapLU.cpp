#include<stdio.h>
#include<math.h>

int main(){
	int n;
	printf("Ma tran vuong A co cap la: ");
	scanf("%d",&n);
	printf("Moi ban nhap ma tran vuong\nDk a11 khac 0 va det A khac 0\n");
	double a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("a[%d][%d] = ",i+1,j+1);
			scanf("%lf",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%.2lf ",a[i][j]);
		}
		printf("\n");
	}	
	//Tim matrix l va u
	double l[n][n] ,u[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		l[i][j]=0;
		u[i][j]=0;
		}
	}	
	//uij = 1 <=> i = j
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				u[i][j]=1;			
			}
		}
	}
	//li1 = ai1, i = 1,n
	for(int i=0;i<n;i++){
		l[i][0] = a[i][0];
	
	} 	
	//u1k = a1k/a11, k =2,n
	for(int j=0;j<n-1;j++){
		u[0][j+1] = a[0][j+1]/a[0][0];
	}
	//Ma tran l luon co i>=j; ma tran u luon co i<=j 		
	for(int j=0;j<n-1;j++){
		for(int i=0;i<n-1;i++){
			if(j<=i){
				double suml = 0;
				for(int k=0;k<j+1;k++){
					
					suml = suml + l[i+1][k]*u[k][j+1]; 
				}
				l[i+1][j+1] = a[i+1][j+1] - suml;
			}
			else{		
				double sumu = 0;
				for(int k=0;k<i+1;k++){
					sumu = sumu + l[i+1][k]*u[k][j+1];
				}
			u[i+1][j+1] = (a[i+1][j+1] - sumu)/l[i+1][i+1];
			}
		}
		
	}

	//In ra ma tran l va u 
	printf("\nMa tran u\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%.2lf  ",u[i][j]);
		}
		printf("\n");
	}	
	printf("\nMa tran l\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%.2lf  ",l[i][j]);
		}
		printf("\n");
	}
	/* Ax = B
	L.U.x = B
	L.y = B => y 
	U.x = y=> x 
	*/
	//Tim y
	double b[n];
	double y[n];
	printf("\nNhap ma tran cot B\n");
	for(int i=0;i<n;i++){
		printf("b[%d] = ",i+1); scanf("%lf",&b[i]);
	}

	y[0] = b[0]/l[0][0];
	for(int i=0;i<n-1;i++){
		double sum = 0;
		for(int j=0;j<i+1;j++){
			sum = sum + l[i+1][j]*y[j];
		}
		y[i+1] = (b[i+1] - sum)/l[i+1][i+1];
	}
	printf("Ma tran cot y\n");
	for(int i=0;i<n;i++){
		printf("%.2lf\n",y[i]); 
	}	
	//Tim x
	double x[n];
	x[n-1] = y[n-1]/u[n-1][n-1];
	for(int i=n-1;i>=0;i--){
		double sum = 0;
		for(int j=n-1;j>i-1;j--){
			sum = sum + u[i-1][j]*x[j];	
		}
		x[i-1] = (y[i-1] - sum)/u[i-1][i-1];
	}
	printf("Ma tran cot x can tim:\n");
	for(int i=0;i<n;i++){
		printf("%.2lf\n",x[i]);	
	}
	return 0;
}
