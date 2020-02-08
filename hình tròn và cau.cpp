#include<iostream>
#include<math.h>
using namespace std;

class HinhHoc
{
public:
    virtual float ChuVi() const=0;
    virtual float DienTich() const =0;

};
class HinhTron : public HinhHoc
{
private:
    float r;
public:
    HinhTron(int _r):r(_r)
    {
        if (r<0) r=1;
    }
    virtual float ChuVi() const
    {
        return 2*3.14159*r;
    }
    virtual float DienTich() const
    {
        return 3.14159*r*r;
    }
    float DuongKinh() const
    {
        return 2*r;
    }
};

//che di phuong thuc DienTich bang viec thua ke private
class HinhCau: private HinhTron// t?i sao private
{
    public:
    HinhCau(int _r):HinhTron(_r) {}
	//phuong thich DuongKing thi van de public
    using HinhTron::DuongKinh;
    float TheTich() const
    {
        return (float)4/3*pow(DuongKinh()/2,3)*3.14159;
    }
};


void menu()
{
	cout<<"1.Tinh chu vi, dien tich, duong kinh hinh tron."<<endl;
	cout<<"2.Tinh the tich hinh cau."<<endl;
	cout<<"3.Thoat."<<endl;
	int lc, r;
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
			HinhCau b(r);
			cout<<"The tich hinh cau: "<<b.TheTich()<<endl;
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
