// le duy dung_ANHTTT

#include <iostream>

using namespace std;

class DaThuc{
	private:
		int a[100];
		int number;
	public:
		DaThuc(int*, int);
		DaThuc();
		DaThuc operator+(DaThuc);
		DaThuc operator-(DaThuc);
		DaThuc operator*(DaThuc);
		DaThuc operator/(DaThuc);
		DaThuc operator*(int);
		void print();
};

void DaThuc::print()
{
	cout<<a[0]<<" + ";
	for (int i = 1; i<this->number -1; i++)
	{
		cout<<a[i]<<"x^"<<i<<" + ";
	}
	cout<<a[this->number - 1]<<"x^"<<(this->number - 1);
}
DaThuc::DaThuc()
{
	
}

DaThuc::DaThuc(int *a, int num)
{
	this->number = num;
	for (int i = 0 ; i<num ; i++)
	this->a[i] = a[i];
}

DaThuc DaThuc::operator+(DaThuc b)
{
	DaThuc result;
	
	if (this->number== b.number)
	{
		result.number = b.number;
		for (int i = 0; i<b.number; i++)
		{
			result.a[i] = this->a[i] + b.a[i];
		}
	}
	if (this->number<b.number)
	{
		result.number = b.number;
		for (int i = 0; i<number; i++)
		{
			result.a[i] = this->a[i] + b.a[i];
		}
		for (int i = number; i<b.number; i++ )
		{
			result.a[i] = b.a[i];
		}
	}
	if (this->number>b.number)
	{
		result.number =  this->number;
		for (int i = 0; i<b.number; i++)
		{
			result.a[i] = this->a[i] + b.a[i];
		}
		for (int i = b.number; i<this->number; i++)
		{
			result.a[i] = this->a[i];
		}
	}
	return result;
}

DaThuc DaThuc::operator-(DaThuc b)
{
	DaThuc result;
	
	if (this->number== b.number)
	{
		result.number = b.number;
		for (int i = 0; i<b.number; i++)
		{
			result.a[i] = this->a[i] - b.a[i];
		}
	}
	if (this->number<b.number)
	{
		result.number = b.number;
		for (int i = 0; i<number; i++)
		{
			result.a[i] = this->a[i] - b.a[i];
		}
		for (int i = number; i<b.number; i++ )
		{
			result.a[i] = -b.a[i];
		}
	}
	if (this->number>b.number)
	{
		result.number = this->number;
		for (int i = 0; i<b.number; i++)
		{
			result.a[i] = this->a[i] - b.a[i];
		}
		for (int i = b.number; i<this->number; i++)
		{
			result.a[i] = this->a[i];
		}
	}
	return result;
}

DaThuc  DaThuc::operator*(DaThuc b)
{
	DaThuc result;
	return result;
}

DaThuc DaThuc::operator/(DaThuc b)
{
	DaThuc result;
	return result;
}

DaThuc DaThuc::operator*(int b)
{
	DaThuc result;
	result.number = this->number;
	for (int i = 0; i<this->number; i++)
	{
		result.a[i] = this->a[i]*b;
	}
	return result;
}

int main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {2,1,3};
	DaThuc d1(a,5),d2(b,3);
	DaThuc result;
	result = d1 + d2;
	result.print();
	return 0;
}
