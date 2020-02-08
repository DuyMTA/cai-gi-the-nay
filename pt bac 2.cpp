#include<iostream>
#include<math.h>
using namespace std;

class Pt_b2
{
private:
    float a, b, c;
public:
    typedef pair<float,float> capnghiem;
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
void menu()
{
	cout<<"1.Tim nghiem pt."<<endl;
	cout<<"2.Thoat"<<endl;
	int lc;
	int x, y, z;
	bool exit = false;
	while(!exit)
	{
		cout<<"\nNhap lua chon: ";
		cin>>lc;
		switch(lc){
			case 1:
				{
					cout<<"Nhap cac he so: "<<endl;
					cout<<"He so x^2: ";
					cin>>x;
					cout<<"He so x: ";
					cin>>y;
					cout<<"He so tu do: ";
					cin>>z;
					Pt_b2 pt(x, y, z);
				    Pt_b2::capnghiem p;
				    bool kt = pt.timnghiem(p);
				    if(kt == false)
				    {
				    	cout<<"Phuong trinh vo nghiem."<<endl;
					}
					else
					{
						if(p.first == p.second)
					    {
					    	cout<<"Phuong trinh co nghiem kep: "<<p.first<<endl;
						}
						else
						{
							cout<<"Phuong trinh co hai nghiem: \nNghiem 1: "<<p.first<<"\nNghiem 2: "<<p.second<<endl;
						}
					}
				    
					break;
				}
			case 2:
				{
					exit = true;
					break;
				}
			default:
				{
					cout<<"Nhap sai lua chon."<<endl;
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
