#include<iostream>

using namespace std;

class Shape
{
	public:
		virtual void area()=0;
};

class Circle : public Shape
{
	private:
		float r;
	public:
		Circle(float r)
		{
			this->r = r;
		}
		void area()
		{
			cout<<"\n Area of a Circle is : "<<(3.14*r*r);
		}
};

class Sphere : public Shape
{
	private:
		float r;
	public:
		Sphere(float r)
		{
			this->r = r;
		}
		void area()
		{
			cout<<"\n Area of a Sphere is : "<<(4*3.14*r*r);
		}
};

class Cylinder : public Shape
{
	private:
		float r,h;
	public:
		Cylinder(float r, float h)
		{
			this->r = r;
			this->h = h;
		}
		void area()
		{
			cout<<"\n Area of a Cylinder is : "<<(2*3.14*r*h);
		}
};

int main()
{
	Circle x1(10.5F);
	Sphere x2(7.5F);
	Cylinder x3(10.5F, 5.0F);
	
	x1.area();
	x2.area();
	x3.area();
	
	return 0;
}
