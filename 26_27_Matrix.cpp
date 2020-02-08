// le duy dung_ANHTTT

#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

const int MAX = 20;

class Matrix
{
	friend istream &operator >> (istream&, Matrix&);
	friend ostream &operator << (ostream&, Matrix&);
	
	private:
		int soHang;
		int soCot;
		int index[MAX+1][MAX+1];
	public:
		Matrix(){};
		~Matrix(){};
		
		Matrix(int h,int c){
			if(h>MAX or h<=0 or c>MAX or c<=0){
				cout<<"\n========= So hang So cot khong phu hop!";
				return;
			}
			else{
			soHang = h;
			soCot = c;			
			for(int i=1 ; i<=soHang ; i++)
			    for(int j=1 ; j<=soCot ; j++)
			        index[i][j] = 0;	
			}
		};
		
		void setData(int i,int j,int value){index[i][j] = value;};
		void setsoHang(int h){soHang = h;};
		void setsoCot(int c){soCot = c;};
		
		int getData(int i,int j){return index[i][j];}
		int getsoHang(){return soHang;};
		int getsoCot(){return soCot;;};
		
		Matrix operator + (Matrix&);		
		Matrix operator - (Matrix&);		
		Matrix operator * (Matrix&);		
		
};

istream &operator >>(istream &in, Matrix &m)
{
	int a;
b:	cout<<"\n Nhap so hang ma tran: ";
	in>>a;
	if(a>MAX or a<=0){
		cout<<"====== Khong phu hop! Nhap lai!";
		goto b;
	}
	else
	m.setsoHang(a);
	
c:	cout<<"\n Nhap so cot ma tran: ";
	in>>a;
	if(a>MAX or a<=0){
		cout<<"====== Khong phu hop! Nhap lai!";
		goto c;
	}
	else
	m.setsoCot(a);
	
	for(int i=1 ; i<=m.getsoHang() ; i++)
	    for(int j=1 ; j<=m.getsoCot() ; j++){
	    	cout<<"\n\t Vi tri ("<<i<<")("<<j<<"): ";
	    	in>>a;
	    	m.setData(i,j,a);
		}	
	
	return in;
}

ostream &operator <<(ostream &out,Matrix &m)
{
	out<<"\n- Ma tran: ";
	for(int i=1 ; i<=m.getsoHang() ; i++){
		out<<"\n";
		for(int j=1 ; j<=m.getsoCot() ; j++){
			out<<"\t"<<m.getData(i,j);
		}
	}
	
	return out;
}

Matrix Matrix::operator +(Matrix &m)
{
	if(this->getsoCot() != m.getsoCot() or this->getsoHang() != m.getsoHang()){
		cout<<" 2 ma tran khac nhau!";
	}
	else{
		
	Matrix M(m.getsoHang(),m.getsoCot());
	
	for(int i=1 ; i<=M.getsoHang() ; i++){
		for(int j=1 ; j<=M.getsoCot() ; j++){
			M.setData(i,j,this->getData(i,j)+m.getData(i,j));
		}
	}
	
	return M;
    }
}

Matrix Matrix::operator -(Matrix &m)
{
	if(this->getsoCot() != m.getsoCot() or this->getsoHang() != m.getsoHang()){
		cout<<" 2 ma tran khac nhau!";
		exit(0);
	}
	else{
		
	Matrix M(m.getsoHang(),m.getsoCot());
	
	for(int i=1 ; i<=M.getsoHang() ; i++){
		for(int j=1 ; j<=M.getsoCot() ; j++){
			M.setData(i,j,this->getData(i,j)-m.getData(i,j));
		}
	}
	
	return M;
    }
}

Matrix Matrix::operator *(Matrix &m)
{
	if(this->getsoCot() != m.getsoHang()){
		cout<<" 2 ma tran khong phu hop!";
		exit(0);
	}
	
	Matrix M(this->getsoHang(),m.getsoCot());
	
	for(int i=1 ; i<=this->getsoHang() ; i++){
		for(int k=1 ; k<=m.getsoCot() ; k++ ){
			M.setData(i,k,0);
			for(int j=1 ; j<=this->getsoCot() ; j++){
				M.setData(i,k,M.getData(i,k)+this->getData(i,j)*m.getData(j,k));
			}
		}
	}
	
	return M;
}

int main()
{
	Matrix M(5,3);  // tao mac dinh voi cap rank la 5

	cout<<M;
	
	Matrix M1;
	cin>>M1;
	cout<<M1;
	
	Matrix M2;
	cin>> M2;
	cout<<M2;
	
	Matrix M3;
	
//	cout<<"\n====Tong la: ";
//	M3=M1+M2;
//	cout<<M3;
//	cout<<"\n====Hieu la: ";
//    M3=M1-M2; 
//	cout<<M3;
//	
	cout<<"\n====Tich la: ";
	M3=M1*M2;
	cout<<M3;
	
		
	return 0;
}

// lam menu neu can...
