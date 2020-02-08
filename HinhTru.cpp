#include <bits/stdc++.h>
using namespace std;

class HinhTru
{
private:
    float h;//chieu cao
    float r;//ban kinh hinh tron
public:
    HinhTru(float chieucao,float bankinh):h(chieucao),r(bankinh)
    {
        if (h<=0) h=1;
        if (r<=0) r=1;
    }
    float DienTichDay() const
    {
        return 3.14159*r*r;
    }
    float TheTich() const
    {
        return 3.14159*r*r*h;
    }
    float DienTichXungQuanh() const
    {
        return 2*3.14159*r*h;
    }

};
int main(){
	HinhTru HinhTru(3,5);
	
	cout<<HinhTru.DienTichDay()<<endl;
	cout<<HinhTru.TheTich()<<endl;
	cout<<HinhTru.DienTichXungQuanh()<<endl;
}
