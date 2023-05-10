#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class Number
{
	private:
		int no;
	public:
		void accept()
		{
			cout<<"\n Enter Number : ";
			cin>>no;
		}
		
		void display()
		{
			cout<<"\n Number is : "<<no;
		}
		
		void operator ++()
		{
			no++;
		}
};

int main()
{
	Number n;
	
	n.accept();
	n.display();
	
	++n;
	n.display();
	
	//n++;
	//n.display();
		
	return 0;
}
