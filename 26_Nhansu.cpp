// le duy dung _ ANHTTT

#include<iostream>
using namespace std;

class NhanSu
{
	private:
		string HoTen;
		int Tuoi;
	public:
		void setHoTen(string str){HoTen = str;};
		void setTuoi(int t){Tuoi= t;};
		string getHoTen(){return HoTen;};
		int getTuoi(){return Tuoi;};
		
};

class GiaoVien : public NhanSu
{
	private:
		string ChuyenNganh;
	public:
		void setChuyenNganh(string str){ChuyenNganh = str;};
		string getChuyenNganh(){return ChuyenNganh;};
		void getData(GiaoVien &G);
		void setData(GiaoVien &G);
};

void GiaoVien::setData(GiaoVien &G)
{
	string str;
	int t;
	cout<<"\n- Nhap Ten giao vien: ";
	getline(cin,str); G.setHoTen(str);
	fflush(stdin);
	cout<<"\n- Nhap tuoi: ";
	cin>>t; G.setTuoi(t);
	fflush(stdin);
	cout<<"\n- Nhap chuyen nganh: ";
	getline(cin,str); G.setChuyenNganh(str);
	fflush(stdin);
}

void GiaoVien::getData(GiaoVien &G)
{
	cout<<"\n- Thong tin giao vien: ";
	cout<<G.getHoTen()<<" ... "<<G.getTuoi()<<" tuoi ... "<<"Chuyen nganh: "<<G.getChuyenNganh();
}

int main()
{
	GiaoVien G;
	G.setData(G);
	G.getData(G);
	
	return 0;
}
