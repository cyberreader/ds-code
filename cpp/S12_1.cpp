#include<iostream>

using namespace std;

class Date
{
	private:
		int dd,mm,yy;
	public:
		Date()
		{
			dd=1;
			mm=1;
			yy=2023;
		}
		Date(int dd, int mm, int yy)
		{
			this->dd=dd;
			this->mm=mm;
			this->yy=yy;
		}
		void display()
		{
			cout<<"\n Date : "<<dd<<"/";
			
			switch(mm)
			{
				case 1:	cout<<"Jan";
						break;
				case 2:	cout<<"Feb";
						break;
				case 3:	cout<<"Mar";
						break;
				case 4:	cout<<"Apr";
						break;
				case 5:	cout<<"May";
						break;
				case 6:	cout<<"June";
						break;
				case 7:	cout<<"July";
						break;
				case 8:	cout<<"Aug";
						break;
				case 9:	cout<<"Sep";
						break;
				case 10:cout<<"Oct";
						break;
				case 11:cout<<"Nov";
						break;
				case 12:cout<<"Dec";
			}
			
			cout<<"/"<<yy;
		}
};

int main()
{
	Date d(4,1,2020);
	
	d.display();
	
	return 0;
}
