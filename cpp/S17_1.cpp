#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class Matrix
{
	private:
		int mat[3][3],i,j;
	public:
		void accept()
		{
			cout<<"\n Enter 3x3 Matrix elements : ";
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cin>>mat[i][j];
				}
			}
		}
		
		void display()
		{
			cout<<"\n Matrix elements : ";
			for(i=0;i<3;i++)
			{
				cout<<endl;
				for(j=0;j<3;j++)
				{
					cout<<" "<<mat[i][j];
				}
			}
		}
		
		Matrix operator -(Matrix m2)
		{
			Matrix m3;
			
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					m3.mat[i][j] = mat[i][j] - m2.mat[i][j];
				}
			}
			
			return m3;
		}
};

int main()
{
	Matrix m1,m2,m3;
	
	m1.accept();
	m2.accept();
	
	m3 = m1-m2;
	
	m1.display();	
	m2.display();	
	m3.display();
		
	return 0;
}
