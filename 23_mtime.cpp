// le duy dung _ ANHTTT

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class mtime 
{
	friend istream& operator >> (istream&, mtime&);  // ham tra ve ieu nhap vao (ban chat la nap chong toan tu)
	friend ostream& operator << (ostream&, mtime&);  // ham tra ve kieu xuat ra
	
	private:
		int hour;
		int minute;
		int second;
	public:
		mtime(){hour=0;minute=0;second=0;};
		mtime(int h,int m,int s){hour=h;minute=m;second=s;};
		void setHour(int h){hour=h;};
		void setMinute(int m){minute=m;};
		void setSecond(int s){second=s;};
		int getHour(){return hour;};
		int getMinute(){return minute;};
		int getSecond(){return second;};
		
		mtime operator + (mtime &T);
};

istream &operator >> (istream &in, mtime &T)
{
    float a;
    
h:  cout<<"\nNhap gio: ";
    if(!(cin>>a) or a-(int)a!=0){
    	cout<<" ERROR ";
    	goto h;
	}
	
	T.setHour(a);

m:  cout<<"\nNhap phut: ";
    if(!(cin>>a) or a-(int)a!=0){
    	cout<<" ERROR ";
    	goto m;
	}
    
    T.setMinute(a);
    
s:  cout<<"\nNhap giay: ";
    if(!(cin>>a) or a-(int)a!=0){
    	cout<<" ERROR ";
    	goto s;
	}
	
	T.setSecond(a);

    if(T.getSecond() >= 60){
    	T.setMinute(T.getMinute() + (T.getSecond()-T.getSecond()%60)/60);
    	T.setSecond(T.getSecond()%60);
	}
	if(T.getMinute() >= 60){
		T.setHour(T.getHour() + (T.getMinute()-T.getMinute()%60)/60);
		T.setMinute(T.getMinute()%60);
	}
	
	return in;
}

ostream &operator << (ostream &out, mtime &T)
{
	cout<<setw(2)<<setfill('0')<<T.getHour()<<" : "<<setw(2)<<setfill('0')<<T.getMinute()<<" : "<<setw(2)<<setfill('0')<<T.getSecond();
	
	return out;
}

mtime mtime::operator + (mtime &T)
{
	mtime a;
	
	a.hour = this->hour + T.hour;
	a.minute = this->minute + T.minute;
	a.second = this->second + T.second;
	
	if(a.second >= 60){
		a.minute ++;
		a.second -= 60;
	} 
	
	if(a.minute >= 60){
		a.hour ++;
		a.minute -= 60;
	}
	
	return a;
}

int main()
{
	mtime T1(10,0,15);
	mtime T2(5,15,48);
	mtime T3;
	
	cout<<T1<<endl;
	cout<<T2;
	T3 = T1 + T2;
	
	cout<<"\n\nTong thoi gian la: "<<T3;
	
	cout<<"\nNhap vao gio thu nhat: ";
	cin>>T1; cout<<T1;
	cout<<"\nNhap vao gio thu hai: ";
	cin>>T2; cout<<T2;
	
	T3 = T1+T2;
	cout<<"\nTong là: ";
	cout<<T3;
	
	return 0;
}
