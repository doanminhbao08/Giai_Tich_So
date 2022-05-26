#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;
void doicho(long double &a, long double &b){
	long double mid;
	mid = a;
	a = b;
	b = mid;
	}
void triet(long double &a, long double &b, long double &a0, long double &b0){
		a = a - a0/b0*b;	
	}

int main(){
	//mo file
	ifstream file;
	file.open("C:\\Users\\Admin\\Documents\\Code\\gaussin.txt");
	if(file.fail() == true){
		cout << "\nKhong ton tai file";	
	}
	
	ofstream fileout;
	fileout.open("C:\\Users\\Admin\\Documents\\Code\\gaussout.txt");
	
	//Nhap ma tran A 
	int h,c;
	file >> h;
	file >> c;
	long double a[h][c];
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			file >> a[i][j];
		}
	}
	//Xuat ma tran A 
	fileout << "\nMa tran bo sung:\n";
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			fileout << a[i][j] << " ";
		}
		fileout << "\n";
	}

	//Dua ve ma tran bac thang
	// f = first
	for(int f=0;f<c;f++){
		//Tim xem cot f co phan tu khac 0 khong
		int dem = 0;
		for(int I=f;I<h;I++){
			if(a[I][f]!=0){
				dem++;
			}
		}

		if(dem>0){
			if(a[f][f]==0){
				//Lam cho hang dau khac 0
				int i = f,j = f;
				//Tim phan tu khac 0
				while (a[i][j]==0){
					i++;	
				}
				//Doi cho hang tim duoc voi hang dau
				for(int j=f;j<c;j++){
					doicho(a[f][j],a[i][j]);
				}
			}
			//triet tieu cac hang phia duoi
			for(int i=f+1;i<h;i++){
				for(int j=c-1;j>=f;j--){
					triet(a[i][j],a[f][j],a[i][f],a[f][f]);
				}	
			}		
		
			
		}	
	
	}
	//Loai bo hang = 0
	int h0 = h;
	for(int i=0;i<h;i++){
		int sum = 0;
		for(int j=0;j<c;j++){
			sum = sum +a[i][j]; 
		}
		if(sum == 0){
			h0 --;
		}
	}
	h = h0;
	//Xuat ma tran A bac thang
	fileout << "\nMa tran bo sung bac thang:\n";
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++){
			fileout << a[i][j] << " ";
		}
		fileout << "\n";
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
	fileout << "\nMang chi so la:";
	for(int i=0;i<h;i++){
		fileout << index[i]+1 << " ";
	}
	//Xuat mang tham so
	fileout << "\nMang tham so la:";
	for(int i=0;i<c-h-1;i++){
		fileout << unindex[i]+1 << " ";
	}
	//Tim nghiem
	if(index[h-1] == c-1){
	 	fileout << "\nPhuong trinh vo nghiem";
	}
	else{
		long double b[h][c-h];
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
		fileout << "\n\nMa tran B:\n";
		for(int i=0;i<h;i++){
			for(int j=0;j<c-h;j++){
				fileout << b[i][j] << " ";
			}
			fileout << "\n";
		}	
		//Tim nghiem
		for(int j=0;j<c-h;j++){
			for(int i=h-1;i>=0;i--){
				long double sum = 0;
				for(int i0=i+1;i0<h;i0++){
					sum = sum + a[i][index[i0]]*b[i0][j]; 
				}
				b[i][j] = (b[i][j] - sum)/a[i][index[i]];
			}				
		}
		//Xuat ma tran b sau bien doi
		fileout << "\nMa tran B sau bien doi:\n";
		for(int i=0;i<h;i++){
			for(int j=0;j<c-h;j++){
				fileout << b[i][j] << " ";
			}
			fileout << "\n";
			
		}
		fileout << "Nghiem cua phuong trinh la: ";
		//Xuat ra nghiem
		for(int i=0;i<h;i++){
			fileout << "\nx" <<index[i]+1 <<" = " << b[i][0];
			for(int j=0;j<c-h-1;j++){
				fileout << " + " << b[i][j+1] <<"x" << unindex[j]+1;
			}	
		}
	}
	
	
	file.close();
	fileout.close();
	system("pause");
	
		
}
