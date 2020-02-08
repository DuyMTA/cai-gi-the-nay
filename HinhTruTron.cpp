#include <bits/stdc++.h>
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
    float TheTich() const { 3.14159*DuongKinh()/4*h;}
};
int main(){
	HinhTron ht(4);
	HinhTruTron htt(4,6);
	cout<<htt.DienTichDay()<<endl;
	cout<<htt.ChuViDay()<<endl;
	cout<<htt.DienTichXungQuanh()<<endl;
	cout<<htt.DienTichToanPhan()<<endl;
}
