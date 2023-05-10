#include<iostream>

using namespace std;

class Weight
{
	private:
		int kg,grm;
	public:
		void accept()
		{
			cout<<"\n Enter Kg : ";
			cin>>kg;
			cout<<"\n Enter Grams : ";
			cin>>grm;		
		}
		
		void display()
		{
			cout<<"\n Kg : "<<kg;
			cout<<"\n Grams : "<<grm;
		}
		
		void operator +=(Weight w2)
		{
			grm += w2.grm;
			kg += w2.kg + (grm/1000);
			grm = grm%1000;
		}
};

int main()
{
	Weight w1,w2;
	
	w1.accept();
	w2.accept();
	
	w1.display();
	w2.display();
	
	w1 += w2;
	
	w1.display();
	
	return 0;
}
