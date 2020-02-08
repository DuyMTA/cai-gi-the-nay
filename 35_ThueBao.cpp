// le duy dung_ANHTTT

#include <iostream>
#include <string>
using namespace std;

class ThueBao{
	private:
		string sdt;
		string name;
	public:
		ThueBao();
		ThueBao(string, string);
		string getSDT()
		{
			return sdt;
		}
		string getName()
		{
			return name;
		}
		void print()
		{
			cout<<"SDT: "<<this->getSDT()<<endl;
         	cout<<"Name: "<<this->getName()<<endl;
		}
		ThueBao& operator=(ThueBao);
};

ThueBao :: ThueBao()
{
	
}

ThueBao::ThueBao(string std, string name)
{
	this->sdt = std;
	this->name = name;
}

ThueBao& ThueBao::operator=(ThueBao a)
{
	this->name = a.name;
	this->sdt = a.sdt;
}
class DanhBa: public ThueBao{
	private:
		int number;
		ThueBao a[100];
	public:
		void setDanhBa(ThueBao*, int );
		void print();
		ThueBao findName(string );
		ThueBao findSDT(string);
};

void DanhBa::setDanhBa(ThueBao *a, int num)
{
	this->number = num;
	for (int i = 0; i<num; i++)
	{
	    this->a[i] = a[i];
	}
}

void DanhBa::print()
{
	for (int i = 0; i<this->number; i++)
	{
		a[i].print();
		cout<<"\n============================\n";
	}
}

ThueBao DanhBa::findName(string name)
{
	for (int i = 0; i<this->number; i++)
	{
		if ((a[i].getName()).compare(name) ==0 ) return a[i];
	}

}

ThueBao DanhBa::findSDT(string sdt)
{
	for (int i = 0; i<this->number; i++)
	{
		if ((a[i].getSDT()).compare(sdt) ==0) return a[i];
	}

}

int main()
{
	ThueBao a("098435","anh"), b("435645","van"), c("456657","dung");
	ThueBao tb[] = {a,b,c};
	DanhBa db;
	db.setDanhBa(tb,3);
	db.print();
	ThueBao x = db.findName("van");
	x.print();
	return 0;
}

