#include<iostream>

using namespace std;

class College
{
	private:
		int id,year;
		char name[20],un[20];
	public:
		friend istream& operator >>(istream&,College&);
		friend ostream& operator <<(ostream&,College&);	
};

istream& operator >>(istream &in,College &c)
{
	cout<<"\n Enter College Details : ";
	in>>c.id>>c.name>>c.un>>c.year;
	return in;
}

ostream& operator <<(ostream &out,College &c)
{
	out<<"\n ID : "<<c.id;
	out<<"\n Name : "<<c.name;
	out<<"\n University : "<<c.un;
	out<<"\n Year : "<<c.year;
	return out;
}
		
int main()
{
	College c;
	
	cin>>c;
	cout<<c;
	
	return 0;
}
