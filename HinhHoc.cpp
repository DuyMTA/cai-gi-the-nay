#include <bits/stdc++.h>
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
int main(){
	HinhChuNhat hcn(3,5);
	HinhTron ht(6);
	cout<<hcn.ChuVi()<<endl;
	cout<<hcn.DienTich()<<endl;
	cout<<ht.ChuVi()<<endl;
	cout<<ht.DienTich()<<endl;
}
