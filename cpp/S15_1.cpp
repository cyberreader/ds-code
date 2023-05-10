#include<iostream>

using namespace std;

class Fraction
{
	private:
		float n1,d1,n2,d2;
	public:
		Fraction(float n1=1,float d1=1,float n2=1,float d2=1)
		{
			this->n1 = n1;
			this->d1 = d1;
			this->n2 = n2;
			this->d2 = d2;
		}
		
		void display()
		{
			float ans = n1/d1 + n2/d2;
			cout<<"\n Ans is : "<<ans;
		}
};

int main()
{
	Fraction f(10,2,10,5);
	
	f.display();
	
	return 0;
}
