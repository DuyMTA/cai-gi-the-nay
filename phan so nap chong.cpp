#include <bits/stdc++.h>
using namespace std;

class PS
{
private:
    int ts, ms;
public:
    PS( );
    PS(int,int );
    PS operator + (const PS&);
    PS operator + (const int& songuyen);
    PS operator -(const PS& );
    friend istream & operator>>(istream & is,PS & ps);
    friend ostream & operator<<(ostream & os,const PS & ps);
    void rutgon();
private:
    int ucln(int a,int b)
    {
        return b?ucln(b,a%b):a;
    }
};
istream & operator>>(istream & is,PS & ps)
{
    cout<<"Nhap tu so:";
    is>>ps.ts;
    cout<<"Nhap mau so:";
    is>>ps.ms;
    return is;
};
ostream & operator<<(ostream & os,const PS & ps)
{
    os<<ps.ts<<"/"<<ps.ms;
    return os;
};
PS::PS()
{
    ts=0;
    ms=1;
};
PS::PS(int TS,int MS)
{
    ts=TS;
    ms=MS;
};
PS PS::operator +(const PS& ps)
{
    PS Tong;
    Tong.ts=ts*ps.ms+ms*ps.ts;
    Tong.ms=ms*ps.ms;
    return Tong;
}
PS PS::operator-(const PS& ps)
{
    PS Hieu;
    Hieu.ts=ts*ps.ms-ms*ps.ts;
    Hieu.ms=ms*ps.ms;
    return Hieu;
};
void PS::rutgon()
{
    int u=ucln(ts,ms);
    ts/=u;
    ms/=u;
}
PS PS::operator+ (const int &songuyen)
{
    PS sohuuti(songuyen*ms,ms);
    return *this+sohuuti;
}
int main(){
	PS so1, so2;
	int a=8;
	cin>>so1;
	so1.rutgon();
	cout<<so1<<endl;
	so2= so1+5;
	cout<<so2;
}
