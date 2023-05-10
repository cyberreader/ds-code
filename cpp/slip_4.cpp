
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Worker
{
		char worker_name[10];
		int no_of_hour_worked;
		public:
			void accept()
			{
				cout<<"Enter name";
				cin>>worker_name;
				cout<<"Enter no of hourse worked";
				cin>>no_of_hour_worked;
				
			}
			void calculate(int pay_rate=30)
			{
				cout<<"salary of worker is:"<<(no_of_hour_worked*10)*pay_rate;
			}
	
};
int main()
{
	Worker w;
	w.accept();
	w.calculate();
    getch();
}
