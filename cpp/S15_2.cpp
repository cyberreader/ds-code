#include<iostream>

using namespace std;

class Seller
{
	private:
		char sname[20],pname[20],month[10];
		int sqty,tqty,comm;
	public:
		void accept()
		{
			cout<<"\n Enter Details : ";
			cout<<"\n Seller Name : ";
			cin>>sname;
			cout<<"\n Product Name : ";
			cin>>pname;
			cout<<"\n Month : ";
			cin>>month;
			cout<<"\n Salse Qty : ";
			cin>>sqty;
			cout<<"\n Target Qty : ";
			cin>>tqty;
		}
		
		void display()
		{
			if(sqty>tqty)
			{
				comm = ((sqty-tqty)*25/100) + (tqty*10/100);
			}
			else if(sqty==tqty)
			{
				comm = tqty*10/100;
			}
			else
			{
				comm = 0;
			}
			
			cout<<"\n Seller Details : ";
			cout<<"\n Seller Name : "<<sname;
			cout<<"\n Product Name : "<<pname;
			cout<<"\n Month : "<<month;
			cout<<"\n Salse Qty : "<<sqty;
			cout<<"\n Target Qty : "<<tqty;
			cout<<"\n Commission : "<<comm;
		}
};

int main()
{
	Seller s[3];
	int i;
	
	for(i=0;i<3;i++)
	{
		s[i].accept();
	}
	
	for(i=0;i<3;i++)
	{
		s[i].display();
	}
	
	return 0;
}
