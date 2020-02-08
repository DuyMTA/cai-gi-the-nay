#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
class huuti	{
  int ts,ms;
	public:
		int operator>(huuti a);
 		 int operator<(huuti a);
  		int operator==(huuti a);
 		 int operator!=(huuti a);
 		 friend ostream &operator<<(ostream &os,huuti &ht);
  		friend istream &operator>>(istream &is,huuti &ht);
  };
  int huuti::operator==(huuti a)
   {
   if(ts*a.ms==ms*a.ts)
     return 1;
   else
     return 0;
   };
// ??nh ngh?a toán t? so sánh khác
   int huuti::operator!=(huuti a)
   {
   if(ts*a.ms!=ms*a.ts)
     return 1;
   else
     return 0;
   };
  int huuti::operator>(huuti a)
   {
   if(ts*a.ms>ms*a.ts)
     return 1;
   else
     return 0;
   };

// ??nh ngh?a toán t? nh? h?n
   int huuti::operator<(huuti a)
   {
   if(ts*a.ms<ms*a.ts)
     return 1;
   else
     return 0;
   };
   ostream &operator<<(ostream &os,huuti &ht)
    {
    os<< " phan so ban vua nhap ==]] ";
    os<<ht.ts<<"/"<<ht.ms<<endl;
    return os;
    };

// ??nh ngh?a toán t? trích dòng
   istream &operator>>(istream &is,huuti &ht)
    {
    cout<<"Nhap tu so: ";
    is>>ht.ts;
    cout<<"Nhap mau so: ";
    is>>ht.ms;
    return is;
    };
class daysohuuti  {
  huuti ht[300];
  public:
  void sapxep();
  int timkiem(huuti a);
  void nhapdht();
  void xuatdht();
  };

  //Dinh nghia cac ham thanh vien cua lop daysohuuti
    void daysohuuti::sapxep()
    {
    int i,j;
    huuti t;
     for(i=0;i<299;i++)
      for(j=0;j<300;j++)
       if(ht[j]<ht[i]) {
	 t=ht[j];
	 ht[j]=ht[i];
	 ht[i]=t;
	 };
    };

// Tìm ki?m s? h?u t?, n?u tìm th?y tr? l?i v? trí s? h?u t? trong dãy, không tìm th?y tr? v? giá tr? 0
    int daysohuuti::timkiem(huuti a)
     {
      int i;
      for(i=0;i<300;i++)  {
       if(ht[i]==a)
	return i;
      };
      return 0;
     };
     void daysohuuti::nhapdht()
     {
      int i,n=0;
      ifstream fi("input.txt", ifstream::in);
  	fi >>  n;
      for(i=0;i<n;i++)   {
       
       fi>>ht[i];
       };
       fi.close();
      };
     void daysohuuti::xuatdht()
     {
      int i;
      ofstream myfile;
    myfile.open ("ltd.txt");
     
    
      for(i=0;i<5;i++)
       myfile <<ht[i];
	   myfile.close();
     };
int main(){
	daysohuuti so1, so2;
	so1.nhapdht();
	so1.xuatdht();
}
