
#include<iostream>
#include<string>
using namespace std;
#include<vector>

class sach{
	  protected:
	  //main fields
	  string MaSach, NgayNhap, NhaXuatBan;
	  int DonGia, SoLuong;
	  //other fields
	  
	  public:
	  //main methods
	  //----in-------
	  sach();
	  sach(string = "", string = "", string = "", int = 0, int = 0);
	 
	  //--------out------
	  void hienThi();
	  virtual float ThanhTien() = 0;
	  //other methods
	  
};
sach::sach(){
	cout<<"Nhap ma sach: ";
	getline(cin, MaSach);
		fflush(stdin);
	cout<<"Nhap ngay nhap: ";
	getline(cin, NgayNhap);
		fflush(stdin);
	cout<<"Nhap nha xuat ban: ";
	getline(cin, NhaXuatBan);
		fflush(stdin);
	cout<<"Nhap don gia: ";
	cin>>DonGia;
	cout<<"Nhap so luong: ";
	cin>>SoLuong;
}
sach::sach(string ms, string nn, string nxb, int dg, int sl)
{
	MaSach = ms;
	NgayNhap = nn;
	NhaXuatBan = nxb;
	DonGia = dg;
	SoLuong = sl;
}
void sach::hienThi()
{
	cout<<"Ma sach: "<<MaSach<<endl;
	cout<<"Ngay nhap: "<<NgayNhap<<endl;
	cout<<"Nha xuat ban: "<<NhaXuatBan<<endl;
	cout<<"Don gia: "<<DonGia<<endl;
	cout<<"So luong: "<<SoLuong<<endl;
}
class sachGT : public sach{
	  private:
	  //main fields
	  bool ConMoi;
	  //other fields
	  
	  public:
	  //main methods
	  sachGT(string = "", string = "", string = "", int = 0, int = 0, bool = true);
	  float ThanhTien();
	  //other methods
	  
};

sachGT::sachGT(string ms, string nn, string nxb, int dg, int sl, bool x) 
: sach(ms, nn, nxb, dg, sl), ConMoi(x)
{
}
float sachGT::ThanhTien()
{
	if(ConMoi)
	{
		return SoLuong * DonGia;
	}
	else return SoLuong * DonGia * 0.5;
}
class sachTK : public sach{
	  private:
	  //main fields
	  float Thue;
	  //other fields
	  
	  public:
	  //main methods
	  sachTK(string = "", string = "", string = "", int = 0, int = 0, float = 0.1);
	  float ThanhTien();
	  
	  //other methods
	  
};
sachTK::sachTK(string ms, string nn, string nxb, int dg, int sl, float x) 
: sach(ms, nn, nxb, dg, sl), Thue(x)
{
}
float sachTK::ThanhTien()
{
	return SoLuong * DonGia + Thue;
}
class ThuVien{
	  private:
	  //main fields
		vector<sach*> DanhSachSach;
	  //other fields

	  public:
	  //main methods
	  ThuVien();
	  ~ThuVien();
	  
	  //other methods

};
ThuVien::ThuVien()
{
	cout<<"1.Nhap them sach."<<endl;
	cout<<"2.Xuat danh sach sach."<<endl;
	cout<<"3.Thoat."<<endl;
	
	int lc;
	bool exit = false;
	while(!exit)
	{
		cout<<"Nhap lua chon: "<<endl;
		cin>>lc;
		switch(lc)
		{
			case 1:
				{
					cout<<"1.Sach giao trinh";
					cout<<"Nhap loai sach: ";
					sach *a = new sach()
					break;
				}
			case 2:
				{
					
					break;
				}
			case 3:
				{
					
					break;
				}
			default:
				{
					
					break;
				}
		}
	}
}

int main()
{


 return 0;
}

