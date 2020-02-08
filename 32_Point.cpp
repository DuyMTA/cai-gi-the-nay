// le duy dung_ANHTTT

#include <iostream>

using namespace std;

class Point2D{
	private:
		int a;
		int b;
	public:
		Point2D(int=0, int =0);
		void setPoint(int, int );
		void getPoint();
};

Point2D::Point2D(int a, int b)
{
	this->a = a;
	this->b = b;
}

void Point2D::setPoint(int a, int b)
{
	this->a = a;
	this->b = b;
}

void Point2D::getPoint()
{
	cout<<a<<" , "<<b;
}


class Point3D: public Point2D{
	private:
		int c;
	public:
		Point3D(int=0, int =0, int =0);
		void setPoint(int , int ,int);
		void getPoint();
};

Point3D::Point3D(int a, int b, int c):Point2D(a,b)
{
	this->c = c;
}
void Point3D:: setPoint(int a, int b, int c)
{
	Point2D::setPoint(a,b);
	this->c = c;
}
void Point3D::getPoint()
{
	Point2D::getPoint(); 
	cout<<" , "<<c;
}

int main()
{
	Point2D p(1,2);
	Point3D d(1,2,3);
	p.getPoint();
	cout<<endl;
	d.getPoint();
	return 0;
}
