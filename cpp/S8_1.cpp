#include<iostream>

using namespace std;

class Number
{
	private:
		static int cnt;
	public:
		void display()
		{
			cnt++;
			cout<<"\n Total "<<cnt<<" times display() called";
		}
};

int Number::cnt=0;

int main()
{
	Number n;
	
	n.display();
	n.display();
	n.display();
	
	return 0;
}
