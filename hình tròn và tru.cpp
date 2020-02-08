#include<iostream>
using namespace std;


class HinhTron
{
private:
    float r;
public:
    HinhTron(int _r):r(_r)
    {
        if (r<0) r=1;
    } 
    float ChuVi() const
    {
    	return 3.14159*2*r;
	}
    float DienTich() const
    {
        return 3.14159*r*r;
    }
    float DuongKinh() const
    {
        return 2*r;
    }
};
class HinhTruTron: private HinhTron
{
    private:
    int h;
    public:
    HinhTruTron(int _r,int _h):HinhTron(_r),h(_h) {}
    using HinhTron::DuongKinh;
    float DienTichDay() const {return HinhTron::DienTich();}
    float ChuViDay() const {return HinhTron::ChuVi();}
    float DienTichXungQuanh() const {return HinhTron::ChuVi()*h;}
    float DienTichToanPhan() const {return 2*HinhTron::DienTich()+DienTichXungQuanh();}
    float TheTich() const {return 3.14159*DuongKinh()/4*h;}
};

void menu()
{
	cout<<"1.Tinh chu vi, dien tich, duong kinh hinh tron."<<endl;
	cout<<"2.Hinh cau."<<endl;
	cout<<"3.Thoat."<<endl;
	int lc;
	int r, h;
	bool exit = false;
	while(!exit){
	cout<<"\nNhap lua chon: "<<endl;
	cin>>lc;
	switch(lc){
		case 1:
		{
			cout<<"Nhap ban kinh: "<<endl;
			cin>>r;
			HinhTron a(r);
			cout<<"Chu vi hinh tron: "<<a.ChuVi()<<", dien tich: "<<a.DienTich()<<", duong kinh: "<<a.DuongKinh()<<endl;
			break;
		}
		case 2:
		{
			cout<<"Nhap ban kinh: "<<endl;
			cin>>r;
			cout<<"Nhap chieu cao: "<<endl;
			cin>>h;
			HinhTruTron b(r, h);
			cout<<"Chu vi mat day: "<<b.ChuViDay()<<", dien tich xung quanh: "<<b.DienTichXungQuanh()<<", dien tich toan phan: "
			<<b.DienTichToanPhan()<<", the tich: "<<b.TheTich()<<endl;
			break;
		}
		case 3:
		{
			exit = true;
			break;
		}
		default:
		{
			cout<<"Sai lua chon."<<endl;
			break;
		}
	}
	}
}
int main()
{
	menu();
	return 0;
}
