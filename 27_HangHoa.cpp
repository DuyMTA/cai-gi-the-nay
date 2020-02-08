#include<iostream>
#include<iomanip>
using namespace std;

class HangHoa
{
	private:
		string maHang;
		string tenHang;
	public:
		HangHoa(){maHang="0";tenHang="NO";};
		HangHoa(string m,string t){maHang=m;tenHang=t;};
		void setMaHang(string str){maHang = str;};
		void setTenHang(string str){tenHang = str;};
		string getMaHang(){return maHang;};
		string getTenHang(){return tenHang;};
};

class HangDienTu : public HangHoa
{
	private:
		string dacTinh;
		int loai;
	public:
		HangDienTu():HangHoa()
		{
			dacTinh = "NO";
			loai = 0;
		};
        HangDienTu(string d,int l):HangHoa("18QS057","Banh mi khong"){
        	dacTinh = d;
        	loai = l;
		}
		void setDacTinh(string str){dacTinh = str;};
		void setLoai(int i){loai = i;};
		string getDacTinh(){return dacTinh;};
		int getLoai(){return loai;};
		void setData(HangDienTu &H);
		void getData(HangDienTu H);
};

void HangDienTu :: setData(HangDienTu &H)
{
	string str;
	int i;
	cout<<"\n- Nhap ma hang: ";
	getline(cin,str);
	H.setMaHang(str);
	fflush(stdin);
	cout<<"\n- Nhap ten hang: ";
	getline(cin,str);
	H.setTenHang(str);
	fflush(stdin);
	cout<<"\n- Nhap dac tinh: ";
	getline(cin,str);
	H.setDacTinh(str);
	fflush(stdin);
	cout<<"\n- Nhap chung loai: ";
	cin>>i;
	H.setLoai(i);
}

void HangDienTu::getData(HangDienTu H)
{
	cout<<"\nMa hang: "<<setw(20)<<H.getMaHang()<<" ___ Ten hang: "<<setw(15)<<H.getTenHang()<<" ___ Dac tinh: "<<setw(20)<<H.getDacTinh()<<" ___ Chung loai: "<<H.getLoai();
}

int main()
{
	HangDienTu H2;
	H2.getData(H2);
	
	HangDienTu H3("Dai,Rong",2);
	H3.getData(H3);
	
	HangDienTu H1;
	
	H1.setData(H1);
	H1.getData(H1);
	
	
	return 0;
}

