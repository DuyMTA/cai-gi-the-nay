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

   // ??nh ngh?a to�n t? so s�nh b?ng
   int sophuc::operator==(sophuc a)
   {
   if	((pt==a.pt)&&(pa==a.pa))
   return 1;
   else 
   return 0;
   };

  // ??nh ngh?a to�n t? so s�nh kh�c
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

// T�m ki?m s? ph?c, n?u t�m th?y tr? l?i v? tr� s? ph?c trong d�y, kh�ng t�m th?y tr? v? gi� tr? 0
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

// ??nh ngh?a to�n t? nh?p d�ng
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
