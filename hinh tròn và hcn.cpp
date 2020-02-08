#include<iostream>
using namespace std;

class HinhHoc
{
public:
    virtual float ChuVi() const = 0;
    virtual float DienTich() const = 0;

};
class HinhChuNhat : public HinhHoc
{
private:
    float a, b;
public:
    HinhChuNhat(int _a, int _b):a(_a),b(_b)
    {
        if (a<0) a=1;
        if (b<0) b=1;
    }
    virtual float ChuVi() const
    {
        return (a+b)*2;
    }
    virtual float DienTich() const
    {
        return a*b;
    }

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

void hinhChuNhat()
{
	
}
void menu()
{
	cout<<"1.Tinh chu vi, dien tich, duong kinh hinh tron."<<endl;
	cout<<"2.Tinh chu vi, dien tich hinh chu nhat."<<endl;
	cout<<"3.Thoat."<<endl;
	int lc;
	int r, x, y;
	bool exit = false;
	while(!exit){
	cout<<"\nNhap lua chon: ";
	cin>>lc;
	switch(lc){
		case 1:
		{
			cout<<"Nhap ban kinh: ";
			cin>>r;
			HinhTron a(r);
			cout<<"Chu vi hinh tron: "<<a.ChuVi()<<", dien tich: "<<a.DienTich()<<", duong kinh: "<<a.DuongKinh()<<endl;
			break;
		}
		case 2:
		{
			cout<<"Nhap chieu dai: ";
			cin>>x;
			cout<<"Nhap chieu rong: ";
			cin>>y;
			HinhChuNhat b(x, y);
			cout<<"Chu vi hinh chu nhat: "<<b.ChuVi()<<", dien tich: "<<b.DienTich()<<endl;
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
