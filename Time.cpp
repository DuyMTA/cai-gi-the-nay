#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;

class Time
{
	friend istream& operator >> (istream&, Time&);
	friend ostream& operator << (ostream&, Time&);
	
	private:
		int gio;
		int phut;
		int giay;
	public:
		Time(){
			gio = 0;
			phut = 0;
			giay = 0;
		}
		Time(int h,int m, int s){
			gio = h;
			phut = m;
			giay = s;
		}
		
		void setGio(int a){gio = a;};
		void setPhut(int a){phut = a;};
		void setGiay(int a){giay = a;};
		int getGio(){return gio;};
		int getPhut(){return phut;};
		int getGiay(){return giay;};
		
	    Time operator + (Time& T);  
	    Time operator - (Time& T);   
	    Time operator ++();   // tien to
	    Time operator ++(int); // hau to
	    Time operator --();
	    Time operator --(int);
	
	    void operator = (Time& T);
	    bool operator ==(Time& T);
	    bool operator > (Time& T);

};

istream& operator >> (istream& in, Time& T)
{
	int a;
	a=-1;
    cout<<"\n\t Nhap gio: ";
	while(a<0){
		in>>a; T.setGio(a);
	}
	a=-1;
    cout<<"\n\t Nhap phut: ";
	while(a<0){
		in>>a; T.setPhut(a);
	}
	a=-1;
    cout<<"\n\t Nhap giay: "; 
	while(a<0){
		in>>a; T.setGiay(a);
	}
	
	// Chuan hoa Giay
	if(T.getGiay() >= 60){
		T.setPhut(T.getPhut()+(T.getGiay()-T.getGiay()%60)/60);
		T.setGiay(T.getGiay()%60);
	}
	
	// Chuan hoa Phut
	if(T.getPhut() >= 60){
		T.setGio(T.getGio()+(T.getPhut()-T.getPhut()%60)/60);
		T.setPhut(T.getPhut()%60);
	}
	
	return in;
	
}

ostream& operator << (ostream& out,Time& T)
{
	out<<"\n\t\t\tÄÄÄÄ> Thoi gian: "<<T.getGio()<<":"<<T.getPhut()<<":"<<T.getGiay();
	return out;
}

void Time:: operator = (Time& T)
{
	this->giay = T.giay;
	this->phut = T.phut;
	this->gio = T.gio;
	
}

Time Time:: operator + (Time& T)
{
    Time a;
    
    a.setGio(this->gio + T.getGio());
    
    a.setPhut(this->phut + T.getPhut());
    
    a.setGiay(this->giay + T.getGiay());
	
	if(a.getGiay() >= 60)
	  {
	  	a.setPhut(a.getPhut() + (a.getGiay() - a.getGiay()%60)/60);
	  	a.setGiay(a.getGiay()%60);
	  }
	
	if(a.getPhut() >= 60){
		a.setGio(a.getGio()+(a.getPhut()-a.getPhut()%60)/60);
		a.setPhut(a.getPhut()%60);	
	}
	
	return a;
}

Time Time:: operator - (Time& T)
{
	Time hieu;
	int a;
	a = this->giay+this->phut*60+this->gio*3600 - (T.getGiay()+T.getPhut()*60+T.getGio()*3600);
	int gio;
	int phut;
	int giay;
	
	int x = 3600;
    while(x>=1){
    	if(x == 3600){
    		gio = (a-a%x)/x;
    		a -= gio*x;
    		x /= 60;
		}
		else
		if(x==60){
			phut = (a-a%x)/x;
			a -= phut*x;
			x/=60;
		}
		else{
			giay = a;
			x=0;
		}   
	}
    
    hieu.setGio(gio);
    hieu.setPhut(phut);
    hieu.setGiay(giay);
	return hieu;
}

Time Time::operator ++ () // ++ tien to
{
	this->giay++;
	
	if(this->giay == 60){
		this->giay = 0;
		this->phut ++;
		if(this->phut == 60){
			this->phut = 0;
			this->gio ++;
		}
	}
	
	return Time(gio,phut,giay);	
}

Time Time::operator ++(int) // hau to
{
	giay++;
	if(giay == 60){
		giay = 0;
		phut ++;
		if(phut == 60){
			phut = 0;
			gio ++;
		}
	}
	
	return Time(gio,phut,giay);
}
Time Time::operator -- () // -- tien to, hau to lam tuong tu, chi khac tham so la int
{
	if(this->giay == 0){
		this->giay = 59;
		if(this->phut == 0){
			this->phut = 59;
			if(this->gio > 0){
				this->gio --;
			}
		}
	}
	else
	this->giay--;
	
	return Time(gio,phut,giay);
}

bool Time::operator == (Time& T)
{
	int a = gio*3600+phut*60+giay;
	int b = T.gio*3600+T.phut*60+T.giay;
	
	if(a==b)
	    return true;
	else 
	return false;
}

bool Time::operator > (Time& T)
{
	int a = gio*3600+phut*60+giay;
	int b = T.gio*3600+T.phut*60+T.giay;
	
	if(a>b)
	    return true;
	else 
	return false;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main()
{
	Time A(4,15,60);
	Time B(2,65,185);
	
//	cin>>A;cout<<A;
//	cin>>B;cout<<B;
	

	cout<<"\n\n\n\nTong thoi gian la: ";
	Time tong = A+B;
	cout<<tong;
	cout<<"\nHieu thoi gian la: ";
	Time hieu = A-B;
	cout<<hieu;
	
	cout<<"\n ++ la: ";
	tong++;
	++hieu;
	cout<<tong<<hieu;
	
	cout<<"\n -- la: ";
	Time C(4,0,0);
	--C;
	cout<<C;
	
	return 0;
}
