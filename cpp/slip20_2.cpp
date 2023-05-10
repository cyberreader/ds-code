#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Inventory
{
	int md,pr,st;
	char com[10];
	public:
		void get()
		{
			cout<<"enter model number :";
			cin>>md;
			cout<<"enter price: ";
			cin>>pr;
			cout<<"enter company name :";
			cin>>com;
			cout<<"enter stock :";
			cin>>st;
			
			cout<<"\n 1.Model number:"<<md;
			cout<<"\n 2.price:"<<pr;
			cout<<"\n 3.company name:"<<com;
			cout<<"\n 4.stock:"<<st;
			
		}
		void sale()
		{
			int nos;
			cout<<"\n Model number :"<<md;
			cout<<"\n stock"<<st;
			cout<<"\n enter the quantity to sale :"<<nos;
			cin>>nos;
			st=st-nos;
			cout<<"\n stock remain:"<<st;
			
		}
		void purches()
		{
			int nop;
			cout<<"\n Model number:"<<md;
			cout<<"\n stock :"<<st;
		    cout<<"\n enter the quantity of purches :"<<nop;
			cin>>nop;
			st=st-nop;
			cout<<"\n stock remain :"<<st;
			
			
		}
};
int main()
{
	int i,n,ch;
	Inventory in[30];

	do
	{
		cout<<"\n 1.Accept and display details";
        cout<<"\n 2.To sale mobile";
		cout<<"\n 3.To purches";
		cout<<"\n 4.Exit";
		cout<<"\n enter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n how many record you need enter :";
				cin>>n;
				for(i=0;i<n;i++)
				in[i].get();
				break;
				case 2:
					for(i=0;i<n;i++)
				in[i].sale();
				break;
				case 3:
					for(i=0;i<n;i++)
				in[i].purches();
				break;
				case 4:
					exit(0);
					default:
						cout<<"worng choice";
					
				}		
				
	}while(ch!=4);

}