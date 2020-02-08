#include <bits/stdc++.h>
using namespace std;

class Pt_b2
{
private:
    float a, b, c;
public:
    typedef std::pair<float,float> capnghiem;
    Pt_b2(float _a,float _b,float _c):a(_a), b(_b), c(_c) {}
    void dat_a(float _a)
    {
        a=_a;
    }
    void dat_b(float _b)
    {
        b=_b;
    }
    void dat_c(float _c)
    {
        c=_c;
    }
    float lay_a() const
    {
        return a;
    }
    float lay_b() const
    {
        return b;
    }
    float lay_c() const
    {
        return c;
    }
    bool timnghiem(capnghiem& nghiem)
    {
        float delta=b*b-4*a*c;
        if (delta<0)
            return false;//ko co nghiem
        nghiem.first=(-b+sqrt(delta))/(2*a);
        nghiem.second=(-b-sqrt(delta))/(2*a);
        return true;//co nghiem
    }

};
int main()
{

    Pt_b2 pt(1,-2,1);
    Pt_b2::capnghiem p;
    pt.timnghiem(p);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}

