#include<iostream>
#include<string.h>

using namespace std;

class String
{
	private:
		char str[100];
	public:
		void accept()
		{
			cout<<"\n Enter String : ";
			cin>>str;
		}
		
		void display()
		{
			cout<<"\n String is : "<<str;
		}
		
		String operator +(String s2)
		{
			String s3;
			
			strcpy(s3.str,str);
			strcat(s3.str,s2.str);
			
			return s3;
		}
};

int main()
{
	String s1,s2,s3;
	
	s1.accept();
	s2.accept();
	
	s3 = s1+s2;
	
	s1.display();
	s2.display();
	s3.display();
	
	return 0;
}
