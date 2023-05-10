#include<iostream>

using namespace std;

int replace(char str[],char ch1,char ch2='*')
{
	int count=0;
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]==ch1)
		{
			str[i]=ch2;
			count++;
		}
	}
	
	return count;
}

int main()
{
	char str[100],ch1,ch2;
		
	cout<<"\n Enter String : ";
	cin>>str;
	
	cout<<"\n Enter Old Character to replace : ";
	cin>>ch1;
	
	//cout<<"\n Enter New Character to replace : ";
	//cin>>ch2;
	//int count = replace(str,ch1,ch2);
	
	int count = replace(str,ch1);
	
	cout<<"\n After Replace : "<<str;
	cout<<"\n Total Replacements : "<<count;
	
	return 0;
}
