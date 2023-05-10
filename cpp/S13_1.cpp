#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class Product
{
	private:
		int id,qty;
		char name[20];
		float price;
		static int cnt;
	public:
		void accept()
		{
			cout<<"\n Enter Product Details : ";
			cin>>id>>name>>qty>>price;
			cnt++;
		}
		void display()
		{
			cout<<endl<<"ID : "<<id;
			cout<<endl<<"Name : "<<name;
			cout<<endl<<"Qty : "<<qty;
			cout<<endl<<"Price : "<<price;
		}
		static void show()
		{
			cout<<"\n Total No. of Products are : "<<cnt;
		}
};

int Product::cnt=0;

int main()
{
	Product p1,p2,p3;
	
	p1.accept();
	p2.accept();
	p3.accept();	
	
	p1.display();	
	p2.display();	
	p3.display();
	
	Product::show();
		
	return 0;
}
