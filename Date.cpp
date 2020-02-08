#include<iostream>
#include<math.h>
using namespace std;

int ThangKhongNhuan[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ThangNhuan[]      = {0,31,29,31,30,31,30,31,31,30,31,30,31};

class Date
{
	public:
		int ngay;
		int thang;
		int nam;
	public:
		Date(){
			ngay = 0;
			thang = 0;
			nam = 0;
		}
		Date(int day,int month,int year){
			ngay = day;
			thang = month;
			nam = year;
		}
		void setNgay(int day){ngay = day;};
		void setThang(int month){thang = month;};
		void setNam(int year){nam = year;};
		int getNgay(){return ngay;};
		int getThang(){return thang;};
		int getNam(){return nam;};
		
		static bool testNamNhuan(Date D);
		static int soNgayTrongThang(Date D);
	    static int khoangCach2Date(Date D, Date C);
};

bool Date::testNamNhuan(Date D)
{
	if(D.getNam()%4==0 and D.getNam()%100!=0)
	   return true;
	return false;
}

int Date::soNgayTrongThang(Date D)
{
	if(D.testNamNhuan(D) == true)
	   return ThangNhuan[D.thang];
	else
	   return ThangKhongNhuan[D.thang];
}

int Date::khoangCach2Date(Date D1,Date D2)
{
	if(D1.nam == D2.nam){
		if(D1.thang == D2.thang){
			// cung nam cung thang
			return abs(D1.ngay - D2.ngay);
		}
		else{
			// cung nam khac thang		
			if(D1.thang > D2.thang){
		    	swap(D1.thang,D2.thang);	
		    	swap(D1.ngay,D2.ngay);
			}
			int dem = 0;
			dem += D1.soNgayTrongThang(D1)-D1.ngay + D2.ngay;
			if(D1.testNamNhuan(D1) == true){
				for(int i=D1.thang+1 ; i< D2.thang ; i++){
				dem +=  ThangNhuan[i];
			}
			}
			else{
				for(int i=D1.thang+1 ; i< D2.thang ; i++){
				dem +=  ThangKhongNhuan[i];
			}
			}
			
			return dem;		
		}
	}
	// khac nam
	else{
//		if(D1.nam > D2.nam){
//			swap(D1.thang,D2.thang);
//			swap(D1.ngay,D2.ngay);
//			swap(D1.nam,D2.nam);
//		}
		
		Date A(31,12,D1.nam);
		Date B(1,1,D2.nam);
		
		int dem ;
		dem += D1.khoangCach2Date(D1,A) + D2.khoangCach2Date(D2,B);
		
		return dem;  
	}
}

int main()
{
	Date A(23,11,1999);
	Date B(26,12,2019);
	Date C(7,5,2004);
	
	if(C.testNamNhuan(C))
	   cout<<"\nC la nam nhuan";
	
	if(A.nam == B.nam)
	   cout<<"\nKhoang cach A,B la: "<<A.khoangCach2Date(A,B);
	else{
		int dem = A.khoangCach2Date(A,B);
		int nam = abs(A.nam - B.nam) - 1;
		if(dem >= 365){
			nam++;
			dem -= 365;
		}
		cout<<"\nKhoang cach A,B la: "<<nam<<" nam "<<dem<<" ngay";
	}
	
	
	return 0;
}


