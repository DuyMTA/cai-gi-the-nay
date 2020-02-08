#include<iostream>
using namespace std;
class matran {
   private:
   int hang,cot;
   int phantu[100][100];
   public:
   friend ostream &operator<<(ostream &os,matran &mt);
   friend istream &operator>>(istream &is,matran &mt);
   matran operator+(matran a);
   matran operator-(matran a);
   matran operator*(matran a);
   };
  ostream &operator<<(ostream &os,matran &mt)
   {
      int i,j;
      for(i=0;i<mt.hang;i++) {
       for(j=0;j<mt.cot;j++)
       os<<mt.phantu[i][j];
       os<<endl;
     };
    return os;
   };
  istream &operator>>(istream &is,matran &mt)
   {
     int i,j;
     cout<<"Nhap so hang ma tran: "<<endl;
     is>>mt.hang;
     cout<<"Nhap so cot ma tran: "<<endl;
     is>>mt.cot;
      for(i=0;i<mt.hang;i++)
       for(j=0;j<mt.cot;j++) {
	cout<<"Nhap phan tu hang "<<i<<" cot "<<j<<endl;
	is>>mt.phantu[i][j];
	};
     return is;
   };


  matran matran::operator+(matran a)
  {
  int i,j ;
  matran mtkq;
   if(hang != a.hang || cot != a.cot) {
      cout<<"Khong the cong 2 ma tran khac kich thuoc";
      exit(1);
      }
   else {
    for (i = 0; i < hang; i++)
     for (j = 0; j < cot; j++)
      mtkq.phantu[i][j] = phantu[i][j] + a.phantu[i][j];
   return mtkq;
   };
  };
  matran matran::operator-(matran a)
  {
  int i,j ;
  matran mtkq;
   if (hang != a.hang || cot != a.cot)  {
      cout<<"Khong the cong 2 ma tran khac kich thuoc";
      exit(1);
      }
   else  {
     for (i = 0; i < hang; i++)
      for (j = 0; j < cot; j++)
       mtkq.phantu[i][j] = phantu[i][j] - a.phantu[i][j];

   return mtkq;
   };
  };

  matran matran::operator*(matran a)
  {
    int i,j,k;
   matran mtkq;
   if (cot !=a.hang) {
      cout<<"Khong the thuc hien nhan 2 ma tran nay";
      exit(1);
      }
    else {
     for (i=0;i<hang;i++)
       for (j=0;j<a.cot;j++)
	{
	    mtkq.phantu[i][j] = 0;
	    for (k=0;k<cot;k++)
		mtkq.phantu[i][j]=mtkq.phantu[i][j]+phantu[i][k]*a.phantu[k][j];
	};
     return mtkq;
     };
   };
   int main(){
   	matran mt1, mt2, mt3;
   	cout<<"nhap ma tran 1: "<<endl;
   	cin>>mt1;
   	cout<<"nhap ma tran 2: "<<endl;
   	cin>>mt2;
   	mt3=mt1+mt2;
   }

