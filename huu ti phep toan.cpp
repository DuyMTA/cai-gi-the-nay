#include <iostream>
using namespace std;

class huuti	{
  int ts,ms;
  public:
  huuti operator+(huuti a);
  huuti operator-(huuti a);
  huuti operator*(huuti a);
  huuti operator/(huuti a);
  void nhap();
  void xuat();
  
  };
  
  //ham sai ==>> tim BCNN
// ??nh ngh?a toán t? c?ng
  huuti huuti::operator+(huuti a)
   {
    huuti kq;
    kq.ts=ts*a.ms+ms*a.ts;
    kq.ms=a.ts*a.ms;
    return kq;
   };

   // ??nh ngh?a toán t? tr?
    huuti huuti::operator-(huuti a)
   {
    huuti kq;
    kq.ts=ts*a.ms-ms*a.ts;
    kq.ms=a.ts*a.ms;
    return kq;
   };

// ??nh ngh?a toán t? nhân
   huuti huuti::operator*(huuti a)
   {
    huuti kq;
    kq.ts=ts*a.ts;
    kq.ms=ms*a.ms;
   return kq;
   };

// ??nh ngh?a toán t? chia
   huuti huuti::operator/(huuti a)
   {
   huuti kq;
   if(a.ts==0)
     exit(1);
   else  {
    kq.ts=ts*a.ms;
    kq.ms=ms*a.ts;
    };
   return kq;
   };
//
void huuti::nhap(){
	cout<<" nhap tu so ";
	cin>> ts;
	cout<<" nhap mau so ";
	cin>> ms;
}
void huuti::xuat(){
	cout<< " ket qua la: ";
	cout<< ts <<" / "<<ms;
	}
   
int main(){
	huuti so1, so2, so3;
	so1.nhap();
	so2.nhap();
	so3= so1 / so2;
	so3.xuat();
}

