#include <bits/stdc++.h>
using namespace std;

class TamGiac
{
public:
    enum dangTamGiac {Thuong, Can, Deu, Vuong};
private:
    float a,b,c;
public:
    TamGiac():a(3),b(4),c(5) {}
    TamGiac(int _a, int _b, int _c):a(_a),b(_b),c(_c)
    {
        if (a+b<=c || b+c<=a || a+c<=b)
        {
            a=3;
            b=4;
            c=5;
        }
    }
    float ChuVi() const
    {
        return (a+b+c);
    }
    float DienTich() const
    {
        float s=0.5*(a+b+c);
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    static  Dang(const TamGiac& tg)
    {
        float a=tg.a,b=tg.b,c=tg.c;
        if (a==b && b==c)
            return Deu;
        if (a==b || b==c || a==c)
            return Can;
        if (c<b) std::swap(c,b);
        if (c<a) std::swap(c,a);
        if (a*a+b*b==c*c)
            return Vuong;
        else
            return Thuong;
    }
};
int main(){
	TamGiac tg1;
	tg1= TamGiac(3,5,5);
	cout<<tg1.ChuVi()<<endl;
	cout<<tg1.DienTich()<<endl;
	cout<<tg1.Dang(tg1);
}
