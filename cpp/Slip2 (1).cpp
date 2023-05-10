#include<iostream>
#include<fstream>

using namespace std;

class Movie
{
	private:
		int year,budget;
		char mname[30],dname[30];
	public:
		void accept()
		{
			cout<<"\n Enter Movie Name : ";
			cin>>mname;
			cout<<"\n Enter Director Name : ";
			cin>>dname;	
			cout<<"\n Enter Release Year : ";
			cin>>year;	
			cout<<"\n Enter Budget : ";
			cin>>budget;	
		}
		
		void display()
		{
			cout<<"\n Movie Name : "<<mname;
			cout<<"\n Director Name : "<<dname;
			cout<<"\n Release Year : "<<year;
			cout<<"\n Movie Budget : "<<budget;
		}
};

int main()
{
	Movie m[100];
	int n,i;
	
	fstream file;
	
	file.open("movie.bat",ios::in|ios::out);
	
	cout<<"\n Enter No. of Movies : ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		m[i].accept();
		file.write((char*) &m[i], sizeof(m[i]));
	}
	
	cout<<"\n Movie Details are : ";
	for(i=0;i<n;i++)
	{
		file.read((char*) &m[i], sizeof(m[i]));
		m[i].display();
	}
	
	file.close();
	
	return 0;
}
