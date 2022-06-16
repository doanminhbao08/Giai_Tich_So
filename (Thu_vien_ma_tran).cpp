#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
//Ham nhap vao cac phan tu cua ma tran
void nhap(double A1[20][20], int row1, int col1){
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			printf("Matrix[%d][%d] = ", i+1, j+1); 
			cin >> A1[i][j];
		}	
	}	
}

//Ham xuat ra cac phan tu cua ma tran
void xuat(double A1[20][20], int row1, int col1){
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			cout << A1[i][j] << "\t";
		}
		cout << "\n";	
	}
}

//Xuat ra cac goi cua thu vien
void xuat_thu_vien(){
	cout << "\nThu vien co cac phep toan la:\n";
	cout << "1) Nhan ma tran A voi mot so\n";
	cout << "2) Tim chuyen vi cua ma tran A\n";
	cout << "3) Cong ma tran A voi ma tran B\n";
	cout << "4) Nhan ma tran A voi ma tran B\n";
	cout << "5) Tinh dinh thuc cua ma tran A\n";
	cout << "6) Tim nghich dao cua ma tran A\n";
}

//Kiem tra ma tran co vuong khong
void kiem_tra_A(int row1, int col1, int &job1){
	if(row1 != col1){
		cout << "\nDay khong phai la ma tran vuong\n";
		while(job1 < 1 || job1 > 4){
			cout << "Moi ban chon cac thu tuc tu 1-4: ";
			cin >> job1;
		}
	}
	else{
		cout << "\nDay la ma tran vuong\n";
		while(job1 < 1 || job1 > 6){
			cout << "Moi ban chon cac thu tuc: ";
			cin >> job1;
		}
	}
	
}

//Nhan ma tran A voi mot so
void nhan_voi_1_so(double A1[20][20], int row1, int col1){
	double x;
	cout << "Nhap so ban muon nhan voi ma tran: ";
	cin >> x;
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			A1[i][j] = A1[i][j]*x;	
		}
	}	
	cout << "\nMa tran A sau khi nhan la:\n";
	xuat(A1, row1, col1);
}

//Chuyen vi cua ma tran
void chuyen_vi(double A1[20][20], int row1, int col1){
	double A2[20][20];
	for(int i=0; i<col1; i++){
		for(int j=0; j<row1; j++){
			A2[i][j] = A1[j][i];	
		}
	}		
	cout << "\nMa tran chuyen vi cua A la:\n";
	xuat(A2, col1, row1);
}

//Cong ma tran A voi ma tran B
void cong_ma_tran(double A1[20][20], int row1, int col1){
	double B[20][20];
	cout << "\nNhap cac phan tu cua ma tran B:\n";
	nhap(B, row1, col1);
	cout << "\nMa tran B la:\n";
	xuat(B, row1, col1);
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			A1[i][j] = A1[i][j] + B[i][j];	
		}
	}	
	cout << "\nTong cua 2 ma tran A va B la:\n";
	xuat(A1, row1, col1);
}

/*Nhan ma tran A voi ma tran B
A co row hang, col cot => B co col hang, col2 cot (n thuoc N*)
*/
void nhan_ma_tran(double A1[20][20], int row1, int col1){
	int col2;
	cout << "\nSo cot cua ma tran B la: ";
	cin >> col2;
	double B[20][20];
	cout << "\nNhap cac phan tu cua ma tran B:\n";
	nhap(B, col1, col2);
	cout << "\nMa tran B la:\n";
	xuat(B, col1, col2);
	/*Tinh tich 2 ma tran
	Ma tran c co row hang va col2 cot
	*/
	double C[20][20];
	for(int i=0; i<row1; i++){
		for(int j=0; j<col2; j++){
			C[i][j]=0;
		}	
	}
	for(int i=0; i<row1; i++){
		for(int j=0; j<col2; j++){
			for(int k=0; k<col1; k++){
				C[i][j] = C[i][j] + A1[i][k]*B[k][j];
			}
		}
	}
	cout << "\nTich ma tran A va ma tran B la:\n";
	xuat(C, row1, col2);
}

/*Tinh dinh thuc cua ma tran
B1: Dua ve ma tran bac thang
B2: detA = tich cac phan tu tren duong cheo
*/

//Cac ham phuc vu cho viec dua ve ma tran bac thang
void doicho(double &a, double &b){
	double mid;
	mid = a;
	a = b;
	b = mid;
}
void triet(double &a, double &b, double &a0, double &b0){
		a = a - a0/b0*b;	
}

double tinh_dinh_thuc(double A1[20][20], int row1){
	double det = 1;
	//Tao bien trung gian luu mang
	double temp[20][20];
	for(int i=0; i<row1 ;i++){
		for(int j=0; j<row1; j++){
			temp[i][j] = A1[i][j];
		}	
	}
	//Dua ve ma tran bac thang
	// f = first
	for(int f=0; f<row1 ;f++){
		//Tim xem cot f co phan tu khac 0 khong
		int dem = 0; 
		for(int i=f; i<row1; i++){
			if(A1[i][f] != 0){
				dem++;
			}
		}
		if(dem > 0){
			if(A1[f][f] == 0){
				//Lam cho hang dau khac 0
				int i = f,j = f;
				//Tim phan tu khac 0
				while (A1[i][j] == 0){
					i++;	
				}
				//Doi cho hang tim duoc voi hang dau
				for(int j=f; j<row1; j++){
					doicho(A1[f][j], A1[i][j]);
				}
			}
			//triet tieu cac hang phia duoi
			for(int i=f+1; i<row1; i++){
				for(int j=row1-1; j>=f; j--){
					triet(A1[i][j], A1[f][j], A1[i][f], A1[f][f]);
				}	
			}		
		
			
		}	
	
	}
	cout << "Ma tran bac thang la:\n";
	xuat(A1, row1, row1);
	for(int i=0; i<row1; i++){
		det = det*A1[i][i];	
	}
	//Tra lai gia tri cho A
	for(int i=0; i<row1 ;i++){
		for(int j=0; j<row1; j++){
		A1[i][j] = temp[i][j];
		}	
	}
	return det;	
}

//Cac ham phuc vu cho tim ma tran nghich dao
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
		xuat(nghich_dao,n,n);	
	}
	else{	
		//Tim ma tran nghich dao cua A(n-1)
		tim_nghich_dao(A, nghich_dao, n-1);
		//Thay doi ma tran nghich dao cua A(n-1) thanh nghich dao cua A(n)
		tim_b(A, nghich_dao, n);	//b la b(n)(n)
		tim_B1(A, nghich_dao, n); // B1 la B(n-1)(1)
		tim_B2(A, nghich_dao, n); // B2 la B(1)(n-1)
		tim_B(A, nghich_dao, n);  // B la B(n-1)		

		cout << "\nMa tran nghich dao cap " << n << ":\n";
		xuat(nghich_dao,n,n);

	}
	
	
		
}
//Tim ma tran nghich dao bang phuong phap vien quanh
void ma_tran_nghich_dao(double A1[20][20], int row1){
	int n = row1;
	double nghich_dao[20][20];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		nghich_dao[i][j] = 0;
		}	
	}
	tim_nghich_dao(A1, nghich_dao, n);
}



int main(){
	double A[20][20];
	int row, col;
	cout << "So hang cua ma tran A la: ";
	cin >> row;
	cout << "So cot cua ma tran A la: ";
	cin >> col;
	cout << "Nhap cac phan tu cua ma tran A:\n";
	nhap(A, row, col);
	cout << "Ma tran A la:\n";
	xuat(A, row, col);
	
	int job;
	xuat_thu_vien();
	kiem_tra_A(row, col, job);
	if(job == 1){
		nhan_voi_1_so(A, row, col);
	}
	else if(job == 2){
		chuyen_vi(A, row, col);
	}
	else if(job == 3){
		cong_ma_tran(A, row, col);
	}
	else if(job == 4){
		nhan_ma_tran(A, row, col);
	}
	else if(job == 5){
		cout << "\nDinh thuc cua ma tran la: " << tinh_dinh_thuc(A, row);
	}
	else if(job == 6){
		if(tinh_dinh_thuc(A,row) == 0){
			cout << "Ma tran suy bien, khong co nghich dao\n";	
		}
		else{
			ma_tran_nghich_dao(A,row);
		}
	}
	cout << "\nCam on ban da su dung chuong trinh !";
	
	
	return 0;
}

