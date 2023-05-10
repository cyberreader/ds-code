#include<iostream>

using namespace std;

class Matrix
{
	private:
		int **p;
		int r,c;
	public:
		Matrix(int r,int c)
		{
			this->r = r;
			this->c = c;
			
			p = new int*[r];
  			for(int i=0;i<r;i++)
  			{
				p[i]=new int[c];
			}
		}
		
		void accept()
		{
			cout<<"\n Enter "<<r<<" x "<<c<<" Matrix Elements : ";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cin>>p[i][j];
				}
			}
		}
		
		void display()
		{
			cout<<"\n Matrix Elements are : ";
			for(int i=0;i<r;i++)
			{
				cout<<endl;
				
				for(int j=0;j<c;j++)
				{
					cout<<"  "<<p[i][j];
				}
			}
		}
		
		void transpose()
		{
			for(int i=0;i<r;i++)
			{
				for(int j=i+1;j<c;j++)
				{
					int temp = p[i][j];
					p[i][j] = p[j][i];
					p[j][i] = temp;
				}
			}
		}
		
		~Matrix()
		{
			delete p;
		}
};

int main()
{
	Matrix m(3,3);
	
	m.accept();
	m.display();
	m.transpose();
	m.display();
	
	return 0;
}
