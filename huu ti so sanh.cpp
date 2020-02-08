#include <iostream>
using namespace std;
class huuti	{
  int ts,ms;
  public:
int operator==(huuti a);
  int operator!=(huuti a);
  int operator>(huuti a);
  int operator<(huuti a);
  void nhap();
  void xuat();
  };
// ??nh ngh?a toán t? so sánh b?ng
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

// ??nh ngh?a toán t? l?n h?n
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
//
void huuti::nhap(){
	cout<<" nhap tu so ";
	cin>> ts;
	cout<<" nhap mau so ";
	cin>> ms;
}
int main(){
	huuti so1, so2;
	so1.nhap();
	so2.nhap();
	if ( so1 == so2) cout<<" so thu nhat bang so thu hai ";
	if ( so1 != so2) {
		cout<<" so thu nhat khac thu hai "<<endl;
		 if ( so1 < so2) cout<<" so thu nhat nho hon so thu hai ";
 		 if ( so1 > so2) cout<<" so thu nhat lon hon so thu hai ";
		
	}
}

