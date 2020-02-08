#include <iostream>
using namespace std;
class sophuc {
  int pt,pa;
  public:
  friend ostream& operator<<(ostream& os,sophuc &sp);
  friend istream& operator>>(istream& is,sophuc &sp);  };

 // ??nh ngh?a toán t? xu?t dòng
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
	sophuc so1, so2;
	cin>>so1;
	cout<<so1;
}

