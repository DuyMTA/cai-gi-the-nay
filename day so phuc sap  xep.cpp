#include<iostream>
#include<math.h>
using namespace std;
class sophuc {
  int pt,pa;
  public:
  float module()
{
	float result;
	result = sqrt(this->pt * this->pt + this->pa * this->pa);
	return result;	
}
  friend ostream& operator<<(ostream& os,sophuc &sp);
  friend istream& operator>>(istream& is,sophuc &sp);
  };
  ostream& operator<<(ostream& os,sophuc &sp)
   {       
    os<<" "<<sp.pt <<" + "<<sp.pa<<"i";    
        
   return os;
   };

// ??nh ngh?a toán t? nh?p dòng
  istream& operator>>(istream& is,sophuc &sp)
  {  
  is>>sp.pt>>sp.pa;
  return is;
  };
class daysophuc {
     sophuc sp[100];
     public:
     void sapxep();     
     void nhapdsp();
     void indsp();
     };

void daysophuc::sapxep()
   {
     int i,j;
     sophuc t;     
     for(int i=0;i<4;i++) 
	  for(int j=i+1;j<5;j++) 
	  if(sp[j].module()<sp[i].module()) {	   
	       t=sp[j];
	       sp[j]=sp[i];
	       sp[i]=t;
	       };	     
   };

void daysophuc::nhapdsp()
   {
     for(int i=0;i<5;i++)   {
      cout<<"Nhap so phuc thu: "<<i<<endl;
      cin>>sp[i];
     };
   };

void daysophuc::indsp()
   {
     for(int i=0;i<5;i++)
      cout<<sp[i]<<endl;
   };
int main(){
	daysophuc d1;
	d1.nhapdsp();
	d1.sapxep();
	d1.indsp();
}

