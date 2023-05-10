#include<iostream.h>
#include<conio.h>

inline float circum(float x)
{
  return (2*3.14*x);
}

inline float area(float x)
{
  return (3.14*x*x);
}

int main()
{
 float r;
 clrscr();

 cout<<"Enter radius of circle:";
 cin>>r;
 cout<<endl<<"Circumference:"<<circum(r);
 cout<<endl<<"Area :"<<area(r);

 return 0;
 getch();
}