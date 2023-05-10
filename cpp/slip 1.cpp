#include<stdio.h>
#include<iostream>
using namespace std;
class Minmax
{
	private:
		int x,y;
		public:
			inline int Min(int x,int y)
			{
				return x<y?x:y;
			}
			inline int Max(int x,int y)
			{
				return x>y?x:y;
			}
};
int main()
{
	int x,y;
	Minmax m;
	cout<<"enter the number "<<endl;
	cin>>x>>y;
	cout<<"\n first number is:  "<<x;
	cout<<"\n second number is: "<<y;
	cout<<"\n minimum number is: "<<m.Min(x,y)<<endl;
	cout<<"maximum number is: "<<m.Max(x,y)<<endl;
	
}
