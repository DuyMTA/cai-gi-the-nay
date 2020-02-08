#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class PS
                    {
                     private:
                                  int ts, ms;
                     public:
                                PS ( );
                                PS (int,int );  
                                PS operator + (PS);
                                PS operator -( );
                  friend istream & operator>>(istream & is,PS & ps){
                  	cout<<"Nhap tu so:";
                         is>>ps.ts;
                         cout<<"Nhap mau so:";
                         is>>ps.ms;
                       return is;
				  }
                  friend ostream & operator<<(ostream & os,PS & ps){
                  	os<<ps.ts<<"/"<<ps.ms;
                       return os;
				  }
			};
                  
                  
                 
                   PS::PS()       
                   {                              
                        ts=0;
                       ms=1;
                  };
                  PS::PS(int TS,int MS)       
                   {
                       ts=TS;
                       ms=MS;           
                    };
                  PS PS::operator + (PS ps)                           
                    {
                      PS Tong;
                      Tong.ts=ts*ps.ms+ms*ps.ts;  
                      Tong.ms=ms*ps.ms;
                      return Tong;
                     }    
                   PS PS::operator-()
                      {
                         ts = - ts;
                         return *this;
                      };
int main(){
	PS so1, so2, so3;
	ifstream fi("vidu.txt", ifstream::in);
	ofstream myfile;
    myfile.open ("out.txt");
	fi>>so1;
	fi>>so2;
	so3= so1+ so2;
	myfile<<so3;
	fi.close();
	myfile.close();
}
