#include<iostream>

using namespace std;

class Time
{
	private:
		int hh,mm,ss;
	public:
		void accept()
		{
			cout<<"\n Enter Time : ";
			cin>>hh>>mm>>ss;
		}
		
		void display()
		{
			cout<<hh<<":"<<mm<<":"<<ss<<endl;
		}
		
		friend void diff(Time,Time);
};

void diff(Time t1,Time t2)
{
	cout<<(t1.hh-t2.hh)<<":"<<(t1.mm-t2.mm)<<":"<<(t1.ss-t2.ss)<<endl;
}

int main()
{
	Time t1,t2;
	
	t1.accept();
	t2.accept();
	t1.display();
	t2.display();
	
	diff(t1,t2);
	
	return 0;
}
