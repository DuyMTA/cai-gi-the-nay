#include <iostream>
using namespace std;

class sophuc {
  int pt,pa;
  public:
  int operator==(sophuc a);
  int operator!=(sophuc a);
  void nhap();
  void xuat();
  };

   // ??nh ngh?a toán t? so sánh b?ng
   int sophuc::operator==(sophuc a)
   {
   if	((pt==a.pt)&&(pa==a.pa))
   return 1;
   else 
   return 0;
   };

  // ??nh ngh?a toán t? so sánh khác
   int sophuc::operator!=(sophuc a)
   {
    if((pt!=a.pt)||(pa!=a.pa))	
   return 1;
   
   return 0; 	
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
	sophuc so1, so2;
	so1.nhap();
	so2.nhap();
	if ( so1 == so2 ) cout<<" 2 so phuc bang nhau ";
	else cout<<" 2 so phuc khac nhau ";
	}
