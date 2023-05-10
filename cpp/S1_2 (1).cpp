#include<iostream>
#include<fstream>

using namespace std;

class MyFile
{
	private:
		ifstream fin;
		char ch,fname[20];
	public:
		void read()
		{
			cout<<"\n Enter File Name : ";
			cin>>fname;
			
			fin.open(fname);
			
			if(fin.fail())
			{
				cout<<"\n File not found";
			}
			else
			{
				while(!fin.eof())
				{
					ch=fin.get();
					cout<<ch;
				}
				
				fin.close();
			}
		}
		
		MyFile operator +(MyFile f2)
		{
			MyFile f3;
			
			f3.open("xyz.txt");
			
			while(!fin.eof())
			{
				ch=fin.get();
				f3.put(ch);
			}
			while(!f2.fin.eof())
			{
				ch=f2.fin.get();
				f3.put(ch);
			}
			
			fin.close();
			f2.fin.close();
			f3.close();
		}
		void operator !()
		{
			
			while(!fin.eof())
			{
				ch=fin.get();
				
				if(ch>='A' && ch<='Z')
				{
					ch=ch+32;
				}
				else if(ch>='a' && ch<='z')
				{
					ch=ch-32;
				}
				
				cout<<ch;
			}
		}	
};

int main()
{
	MyFile f1,f2;
	
	f1.read();
	f2.read();
	
	f3 = f1+f2;
	!f3;
	
	return 0;
}
