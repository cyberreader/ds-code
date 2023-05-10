#include<iostream>

using namespace std;

class MyArray
{
	private:
		int *arr,i,n;
	public:
		MyArray()
		{
			n=0;
			arr=NULL;
		}
		MyArray(int n)
		{
			this->n=n;
			arr=new int[n];
		}
		void accept()
		{
			cout<<"\n Enter Array elements : ";
			for(i=0;i<n;i++)
			{
				cin>>arr[i];
			}
		}
		void display()
		{
			int sum=0;
			for(i=0;i<n;i++)
			{
				sum=sum+arr[i];
			}
			cout<<"\n Sum is : "<<sum;
		}
		~MyArray()
		{
			delete arr;
		}
};

int main()
{
	MyArray m(5);
	
	m.accept();
	m.display();
	
	return 0;
}
