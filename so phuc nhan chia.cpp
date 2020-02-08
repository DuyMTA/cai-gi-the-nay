#include<iostream>
using namespace std;
class sophuc {
  int pt,pa;
  public:  
  sophuc operator*(sophuc a);
  sophuc operator/(sophuc a);
  void nhap();
  void xuat();
  
  };
   // ??nh ngh?a toán t? nhân
   sophuc sophuc::operator*(sophuc a)
   {
   sophuc kq;
   kq.pt=pt*a.pt-pa*a.pa;
   kq.pa=pt*a.pa+pa*a.pt;
   return kq;
   };

  // ??nh ngh?a toán t? chia
   sophuc sophuc::operator/(sophuc a)
   {
   sophuc kq;
   kq.pt=pt*a.pt+pa*a.pa/(a.pt*a.pt+a.pa*a.pa);
   kq.pa=pa*a.pt-pt*a.pa/(a.pt*a.pt+a.pa*a.pa);
   return kq;
   };
void sophuc::nhap(){
	cout<<"nhap phan thuc: ";
	cin>>pt;
	cout<<"nhap phan ao: ";
	cin>>pa;
}
void sophuc::xuat(){
	cout<< pt <<" + "<<pa<<"i";
}
int main()
{
	sophuc so1, so2, so3;
	so1.nhap();
	so2.nhap();
	so3= so1*so2;
	so3.xuat();
	}
