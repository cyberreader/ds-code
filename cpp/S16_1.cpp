#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class Machine
{
	private:
		int id;
		char name[20];
		float price;
	public:
		Machine(int id,char name[],float price)
		{
			this->id = id;
			strcpy(this->name,name);
			this->price = price;
		}
		
		Machine(Machine &m)
		{
			this->id = m.id;
			strcpy(this->name,m.name);
			this->price = m.price;
		}
		
		void display()
		{
			cout<<endl<<"ID : "<<setw(10)<<id;
			cout<<endl<<"Name : "<<setw(20)<<name;
			cout<<endl<<"Price : "<<setw(20)<<price;
		}
};

int main()
{
	Machine m1(1,"abc",25000);
	Machine m2(m1);
	
	m1.display();
	m2.display();
	
	return 0;
}
