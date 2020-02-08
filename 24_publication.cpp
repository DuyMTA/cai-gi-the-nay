// le duy dung _ ANHTTT

#include<iostream>
using namespace std;

class publication
{
	private:
		string title;  // tua de
		float  price;  // gia ca
	public:
		publication(){title = "";price=0;};
		publication(string t,float p){title = t; price = p;};
		
		void setTitle(string t){title = t;};
		void setPrice(float p){price = p;};
		string getTitle(){return title;};
		float getPrice(){return price;};
		
};


class book : public publication
{
	private:
		int page;    // so trang
	public:
		void setData(book &B);
		void getData(book B);
		void setPage(int p){page = p;};
		int getPage(){return page;};
};

void book::setData(book &B)
{
	string str;
	float f;
	int i;
	
	cout<<"\n- Nhap ten sach: ";
	getline(cin,str); B.setTitle(str);
	fflush(stdin);
	cout<<"\n- Nhap gia($): ";
	cin>>f; B.setPrice(f);
	fflush(stdin);
	cout<<"\n- Nhap so trang: ";
	cin>>i; B.setPage(i);
	fflush(stdin);
	
}

void book::getData(book B)
{
	cout<<"\nThong tin sach: ";
	cout<<B.getTitle()<<" ... "<<B.getPrice()<<" $ ... "<<B.getPage()<<" trang";
}

class tape : public publication
{
	private:
		float time;   // thoi luong
	public:
		void setTime(float t){time = t;};
        float getTime(){return time;};
		void setData(tape &T);
		void getData(tape T);	
};

void tape::setData(tape &T)
{
	string str;
	float f;
	float i;
	
	cout<<"\n- Nhap ten sach: ";
	getline(cin,str); T.setTitle(str);
	fflush(stdin);
	cout<<"\n- Nhap gia($): ";
	cin>>f; T.setPrice(f);
	fflush(stdin);
	cout<<"\n- Nhap thoi luong: ";
	cin>>i; T.setTime(i);
	fflush(stdin);
}

void tape::getData(tape T)
{
	cout<<"\nThoi luong sach: ";
	cout<<T.getTitle()<<" ... "<<T.getPrice()<<" $ ... "<<T.getTime()<<" gio";
}

int main()
{
	book B[100];
	tape T[100];
	
	B[0].setData(B[0]);
	B[0].getData(B[0]);
	
	T[0].setData(T[0]);
	T[0].getData(T[0]);
	
	return 0;
}
