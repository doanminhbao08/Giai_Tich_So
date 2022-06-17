#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;
void doicho(double &a,double &b){
	long double mid;
	mid = a;
	a = b;
	b = mid;
	}
void triet(double &a, double &b, double &a0, double &b0){
		a = a - a0/b0*b;	
	}

int main(){
	//mo file
	ifstream file;
	file.open("C:\\Users\\Admin\\Documents\\Code\\gaussin.txt");
	if(file.fail() == true){
		cout << "\nKhong ton tai file";	
	}
	
	
	//Nhap ma tran A 
	int h,c;
	file >> h;
	file >> c;
	double a[h][c];
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			file >> a[i][j];
		}
	}
	//Xuat ma tran A 
	cout << "\nMa tran bo sung:\n";
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	//Dua ve ma tran bac thang
	// f = first
	int f0 = 0;
	for(int f=0;f<h;f++){
		//Tim xem cot f co phan tu khac 0 khong
		int dem = 0;
		for(int i=f;i<h;i++){
			if(a[i][f0]!=0){
				dem++;
			}
		}		
		if(dem>0){
			if(a[f][f0]==0){
				//Lam cho hang dau khac 0
				int i = f;
				//Tim phan tu khac 0
				while (a[i][f0]==0){
					i++;	
				}
				//Doi cho hang tim duoc voi hang dau
				for(int j=f0;j<c;j++){
					doicho(a[f][j],a[i][j]);
				}
			}
			//triet tieu cac hang phia duoi
			for(int i=f+1;i<h;i++){
				for(int j=c-1;j>f0;j--){
					triet(a[i][j],a[f][j],a[i][f0],a[f][f0]);
				}	
				a[i][f0]=0;
			}		
		cout << "\nMa tran bo sung bac thang:\n";
		for(int i=0;i<h;i++){
			for(int j=0;j<c;j++){
				cout << a[i][j] << " ";			}
			cout << "\n";
		}
			
		}
		else{
			f--;
		}
		f0 ++;	
	
	}
	//Loai bo hang = 0
	int h0 = h;
	for(int i=0;i<h;i++){
		double dem = 0;
		for(int j=0;j<c;j++){
			if(a[i][j] != 0){
				dem++;
			}
		}
		if(dem == 0){
			h0 --;
		}
	}
	h = h0;

	//Xuat ma tran A bac thang
	cout << "\nMa tran bo sung bac thang:\n";
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	/*
	Tim nghiem 
	+ rA = rA' => PT co nghiem 
	+ n = rA => PT co nghiem duy nhat
	- n < rA => PT vo so nghiem 
	rA < rA' => PT vo nghiem 
	*/
	//Tim phan tu dau tien khac 0 o cac hang
	int index[h], unindex[c-h-1];
	for(int i=0;i<h;i++){
		int j = 0;
		while(a[i][j] == 0){
			j++;
		}
		index[i] = j;
	}
	//Tim cac hang la tham so
	int k = 0;
	for(int j=0;j<c-1;j++){
		int sum=0;
		for(int i=0;i<h;i++){
			if(j == index[i]){
				sum++;
			}	
		}
		if(sum==0){
		unindex[k] = j;
		k++;	
		}
	}
	//Xuat mang chi so
	cout << "\nMang chi so la:";
	for(int i=0;i<h;i++){
		cout << index[i]+1 << " ";
	}
	//Xuat mang tham so
	cout << "\nMang tham so la:";
	for(int i=0;i<c-h-1;i++){
		cout << unindex[i]+1 << " ";
	}
	//Tim nghiem
	if(index[h-1] == c-1){
	 	cout << "\nPhuong trinh vo nghiem";
	}
	else{
		double b[h][c-h];
		//cot cuoi
		for(int i=0;i<h;i++){
			b[i][0] = a[i][c-1];
		}
		//cot tiep theo
		int j1 = 1;
		for(int j=0;j<c-1;j++){
			int sum = 0;
			for(int i=0;i<h;i++){
				if(j == index[i]){
					sum++;
				}	
			}
			if(sum == 0){
				for(int i=0;i<h;i++){
					b[i][j1] = -a[i][j];
				}
				j1++;	
			}
			
		}
		//Xuat ma tran b
		cout << "\n\nMa tran B:\n";
		for(int i=0;i<h;i++){
			for(int j=0;j<c-h;j++){
				cout << b[i][j] << " ";
			}
			cout << "\n";
		}	
		//Tim nghiem
		for(int j=0;j<c-h;j++){
			for(int i=h-1;i>=0;i--){
				double sum = 0;
				for(int i0=i+1;i0<h;i0++){
					sum = sum + a[i][index[i0]]*b[i0][j]; 
				}
				b[i][j] = (b[i][j] - sum)/a[i][index[i]];
			}				
		}
		//Xuat ma tran b sau bien doi
		cout << "\nMa tran B sau bien doi:\n";
		for(int i=0;i<h;i++){
			for(int j=0;j<c-h;j++){
				cout << b[i][j] << " ";
			}
			cout << "\n";
			
		}
		cout << "Nghiem cua phuong trinh la: ";
		//Xuat ra nghiem
		for(int i=0;i<h;i++){
			cout << "\nx" <<index[i]+1 <<" = " << b[i][0];
			for(int j=0;j<c-h-1;j++){
				cout << " + " << b[i][j+1] <<"x" << unindex[j]+1;
			}	
		}
	}
	
	
	
		
}
