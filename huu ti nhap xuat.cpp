#include <iostream>
using namespace std;

class huuti	{
  int ts,ms;
  public:
  friend ostream &operator<<(ostream &os,huuti &ht);
  friend istream &operator>>(istream &is,huuti &ht);
  };
// ??nh ngh?a toán t? chèn dòng
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
int main(){
	huuti so1, so2;
	cin>> so1;
	cout<< so1;
	cin>> so2;
	cout <<so2;
}
