#include<iostream>

using namespace std;

class Vector
{
	private:
		int *v,n,i;
	public:
		Vector(int n)
		{
			this->n = n;
			v = new int[n];
		}
		
		void accept()
		{
			cout<<"\n Enter Vector Elements : ";
			for(i=0;i<n;i++)
			{
				cin>>v[i];
			}	
		}
		
		void display()
		{
			cout<<"\n Vector is : (";
			for(i=0;i<n;i++)
			{
				cout<<v[i]<<",";
			}	
			cout<<")";
		}
		
		void union_ele(Vector v2)
		{
			cout<<"\n Vector is : (";
			for(i=0;i<n;i++)
			{
				cout<<v[i]<<",";
			}
			
			x: for(int j=0;j<v2.n;j++)
			{
				for(i=0;i<n;i++)
				{
					if(v2.v[j]==v[i])
					{
						continue x;
					}
				}
				
				cout<<v2.v[j]<<",";	
			}
			cout<<")";
		}
};

int main()
{
	Vector v1(5),v2(5);
	
	v1.accept();
	v2.accept();
	
	v1.display();
	v2.display();
	
	v1.union_ele(v2);
	
	return 0;
}
