#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date():day(1),month(1),year(1)
	{}
	Date(int d, int m, int y):day(d),month(m),year(y)
	{
		//kiem tra tinh hop le cua ngay thang, neu vi pham
		//gan ve gia tri mac dinh
		static int nm[]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(year<0) year=1;
		if(IsLeapYear(year)) nm[1]=29;
		if(month>12 || month<=0) month=1;
		if(day<=0 || day>nm[month-1]) day=1;
	}	
	static bool IsLeapYear(int year)
	{ 
		if( (year%4 == 0) && (year%100 != 0) )
		return true;
		else return false;
	}
	int TimeSpan()
	{
		
		static int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
		int i=0;
		int n = 0;
		if(IsLeapYear(year)) m[1]=29;
		else m[1]=28;
		while(i<month-1)
			n+=m[i++];
		n+=day;
		return n;
	}
};
	
int main(){
	Date day1, day2;
	day1=Date(01,12,1999);
	
	cout<<" Da troi qua "<< day1.TimeSpan();
	
}
