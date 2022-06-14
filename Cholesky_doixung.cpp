#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;


int main(){
	//mo file
	ifstream file;
	/*chu y thay doi dia chi cua file
	co the tim dia chi cua file bang cach vao properties cua file roi copy phan location
	thay doi '\' thanh '\\'
	*/
	file.open("C:\\Users\\Admin\\Documents\\Code\\Cholesky.txt"); 
	if(file.fail() == true){
		cout << "\nKhong ton tai file";	
	}
	
	//Ma tran co n*n
	int n;
	file >> n;
	double A[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		file >> A[i][j];	
		}
	}
	
	//In ra ma tran A
	printf("Ma tran A la:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%.2lf\t",A[i][j]);	
		}
		printf("\n");
	}
	//Kiem tra ma tran da doi xung chua, neu chua thi AT.Ax = AT.B
	int kiem_tra = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[i][j] != A[j][i]){
				kiem_tra++;
			}
		}
	}
	double AT[n][n];	
	if(kiem_tra != 0){
		printf("\nMa tran chua doi xung\n");
 		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			AT[i][j] = A[j][i];	
			}
		}
		//In ra ma tran AT
		printf("\nMa tran AT la:\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%.2lf\t",AT[i][j]);	
			}
			printf("\n");
		}
		//nhan 2 ma tran vao ma tran trung gian	
		int temp[n][n];
 		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			temp[i][j] = 0;	
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					temp[i][j] = temp[i][j] + AT[i][k]*A[k][j];
					
				}
			}
		}
		//gan lai gia tri cho A
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				A[i][j] = temp[i][j];
			}

		}
		//In ra ma tran A
		printf("\nMa tran A moi la:\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%.1lf\t",A[i][j]);	
			}
			printf("\n");
		}
	
					

	}
		
	

	//Tim U sao cho A=UT.U
	double U[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		U[i][j] = 0;	
		}
	}
	
	U[0][0] = sqrt(A[0][0]);
	
	for(int j=1;j<n;j++){
		U[0][j] = A[0][j]/U[0][0];
	}
	
	for (int k=1;k<n;k++){
		//Tim phan tu tren duong cheo
		double sum1 = 0;
		for(int i=0;i<=k-1;i++){
			sum1 = pow(U[i][k],2) + sum1;
		}
		U[k][k] = sqrt(A[k][k] - sum1);
		//Tim cac phan tu con lai cung hang
		for(int j=k+1;j<n;j++){
			double sum2 = 0;
			for(int i=0;i<=k-1;i++){
				sum2 = U[i][k]*U[i][j] + sum2;
			}
			U[k][j] = (A[k][j] - sum2)/U[k][k];
		}
		
	}
	
	//In ra ma tran U
	printf("\nMa tran U la:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%.2lf\t",U[i][j]);	
		}
		printf("\n");	
	}
	//In ra ma tran UT
	double L[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		L[i][j] = U[j][i];	
		}
	}	
	printf("\nMa tran UT la:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		printf("%.2lf\t",L[i][j]);	
		}
		printf("\n");	
	}	

	/* Ax = B
	UT.U.x = B
	UT.y = B => y 
	U.x = y=> x 
	*/
	//Tim y
	double b[n];
	double y[n];
	for(int i=0;i<n;i++){
		file >> b[i];
	}
	if(kiem_tra != 0){
		//B = AT.B
		//nhan 2 ma tran vao ma tran trung gian	
		int temp[n];
 		for(int i=0;i<n;i++){
			temp[i] = 0;	
		}
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				temp[i] = temp[i] + AT[i][k]*b[k];
					
			}
		}
		
		//gan lai gia tri cho B
		for(int i=0;i<n;i++){
			b[i] = temp[i];	
		}
	}
	
	//In ma tran cot B
	printf("\nMa tran cot B la\n");
	for(int i=0;i<n;i++){
		printf("%.2lf\n",b[i]);
	}

	y[0] = b[0]/L[0][0];
	for(int i=0;i<n-1;i++){
		double sum = 0;
		for(int j=0;j<i+1;j++){
			sum = sum + L[i+1][j]*y[j];
		}
		y[i+1] = (b[i+1] - sum)/L[i+1][i+1];
	}
	printf("\nMa tran cot Y\n");
	for(int i=0;i<n;i++){
		printf("%.2lf\n",y[i]); 
	}	
	//Tim x
	double x[n];
	x[n-1] = y[n-1]/U[n-1][n-1];
	for(int i=n-1;i>=0;i--){
		double sum = 0;
		for(int j=n-1;j>i-1;j--){
			sum = sum + U[i-1][j]*x[j];	
		}
		x[i-1] = (y[i-1] - sum)/U[i-1][i-1];
	}
	printf("Ma tran cot X can tim:\n");
	for(int i=0;i<n;i++){
		printf("%.6lf\n",x[i]);	
	}

	

	return 0;
}

