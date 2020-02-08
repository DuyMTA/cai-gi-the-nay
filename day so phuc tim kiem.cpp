#include<iostream>
using namespace std;
class sophuc {
  int pt,pa;
  public:
  int operator==(sophuc a);
  int operator!=(sophuc a);
  friend ostream& operator<<(ostream& os,sophuc &sp);
  friend istream& operator>>(istream& is,sophuc &sp);
  
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

class daysophuc {
     sophuc sp[100];
     public:
     int timkiem(sophuc a);
     void nhapdsp();
     void indsp();
     };

// Tìm ki?m s? ph?c, n?u tìm th?y tr? l?i v? trí s? ph?c trong dãy, không tìm th?y tr? v? giá tr? 0
int daysophuc::timkiem(sophuc a)
  {
   int i;
   for(i=0;i<100;i++)   {
      if(sp[i]==a)
          return i;      
    };
return 0;
};

void daysophuc::nhapdsp()
   {
     for(int i=0;i<100;i++)   {
      cout<<"Nhap so phuc thu: "<<i<<endl;
      cin>>sp[i];
     };
   };

   void daysophuc::indsp()
   {
     for(int i=0;i<100;i++)
      cout<<sp[i]<<endl;
   };
    ostream& operator<<(ostream& os,sophuc &sp)
   {       
    os<<"Phan thuc la: "<<sp.pt;    
    os<<"Phan ao la: "<<sp.pa ;    
   return os;
   };

// ??nh ngh?a toán t? nh?p dòng
  istream& operator>>(istream& is,sophuc &sp)
  {  
  is>>sp.pt>>sp.pa;
  return is;
  };
int main(){
	sophuc so1;
	cin>>so1;
	daysophuc d1;
	d1.nhapdsp();
	d1.indsp();
	d1.timkiem(so1);
}
