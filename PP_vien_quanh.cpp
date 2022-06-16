#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;
//Ham xuat ra cac phan tu cua ma tran
void xuat(double A[20][20], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%.3lf\t\t", A[i][j]);
		}
		cout << "\n";	
	}
}
//Ham tinh mau cua bieu thuc
double mau(double A[20][20],double nghich_dao[20][20],int n){
	double tich1[n-1];
	for(int j=0; j<n-1; j++){
		tich1[j] = 0;
		for(int i=0; i<n-1; i++){
			tich1[j] = tich1[j] + A[n-1][i]*nghich_dao[i][j];
		}	
	}
	double tich = 0;
	for(int j=0; j<n-1; j++){
		tich = tich + tich1[j]*A[j][n-1];	
	}
	return A[n-1][n-1] - tich;	

}

//Tim b(n)(n)
void tim_b(double A[20][20],double nghich_dao[20][20],int n){
	nghich_dao[n-1][n-1] = 1/mau(A, nghich_dao, n);
}

//Tim B(n-1)(1)
void tim_B1(double A[20][20],double nghich_dao[20][20],int n){
	double tu_so[n-1];
	for(int i=0; i<n-1; i++){
		tu_so[i] = 0;
		for(int j=0; j<n-1; j++){
			tu_so[i] = tu_so[i] + nghich_dao[i][j]*A[j][n-1];
		}	
	}
	for(int i=0; i<n-1; i++){
		nghich_dao[i][n-1] = - tu_so[i]/mau(A, nghich_dao, n);
	}
}

//Tim B(1)(n-1)
void tim_B2(double A[20][20],double nghich_dao[20][20],int n){
	double tu_so[n-1];
	for(int j=0; j<n-1; j++){
		tu_so[j] = 0;
		for(int i=0; i<n-1; i++){
			tu_so[j] = tu_so[j] + A[n-1][i]*nghich_dao[i][j];
		}	
	}
	for(int j=0; j<n-1; j++){
		nghich_dao[n-1][j] = - tu_so[j]/mau(A, nghich_dao, n);
	}
}

//Tim B
void tim_B(double A[20][20],double nghich_dao[20][20],int n){
	double C[20][20]; 
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			C[i][j] = - A[i][n-1]*nghich_dao[n-1][j];
		}
	}
	for(int i =0; i<n-1; i++){
		C[i][i] = C[i][i] + 1;
	}
	cout << "\n";

	
	double D[20][20];
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			for(int k=0; k<n-1; k++){
				D[i][j] = D[i][j] + nghich_dao[i][k]*C[k][j];	
			}
		}
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			nghich_dao[i][j] = D[i][j];
		}
	}
}

//Tim ma tran nghich dao
void tim_nghich_dao(double A[20][20], double nghich_dao[20][20], int n){
	if(n == 1){
		for(int i=0; i<n-1; i++){
			for(int j=0; j<n-1; j++){
				nghich_dao[i][j] = 0;
			}
		}
		nghich_dao[0][0] = 1/A[0][0];
		cout << "\nMa tran nghich dao cap 1:\n";
		xuat(nghich_dao,n);	
	}
	else{	
		//Tim ma tran nghich dao cua A(n-1)
		tim_nghich_dao(A, nghich_dao, n-1);
		if(mau == 0){
			cout << 
		}
		//Thay doi ma tran nghich dao cua A(n-1) thanh nghich dao cua A(n)
		tim_b(A, nghich_dao, n);	//b la b(n)(n)
		tim_B1(A, nghich_dao, n); // B1 la B(n-1)(1)
		tim_B2(A, nghich_dao, n); // B2 la B(1)(n-1)
		tim_B(A, nghich_dao, n);  // B la B(n-1)		

		cout << "\nMa tran nghich dao cap " << n << ":\n";
		xuat(nghich_dao,n);

	}
	
	
		
}
int main(){
	double A[20][20];
	int n;
	//mo file
	ifstream file;
	/*chu y thay doi dia chi cua file
	co the tim dia chi cua file bang cach vao properties cua file roi copy phan location
	thay doi '\' thanh '\\'
	*/
	file.open("C:\\Users\\Admin\\Documents\\Code\\PP_vien_quanh.txt"); 
	if(file.fail() == true){
		cout << "\nKhong ton tai file";	
	}
	file >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			file >> A[i][j];
		}	
	}
	cout << "Ma tran A la:\n";
	xuat(A,n);
	double nghich_dao[20][20];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		nghich_dao[i][j] = 0;
		}	
	}
	tim_nghich_dao(A, nghich_dao, n);
	
	
	return 0;
}

