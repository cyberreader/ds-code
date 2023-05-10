#include<iostream>
using namespace std;
class Point
{
	int X,Y;
	public:
		Point()
		{
			X=0;
			Y=0;
		}
		void setpoint(int a,int b)
		{
			X=a;
			Y=b;
		}
		int getX()
		{
			return X ;
		}
		int getY()
		{
			return Y ;
			
		}
		void showpoint()
		{
			cout<<"("<<X<<","<<Y<<")";
		
		}
		
		};
		int main()
		{
			Point p1;
			p1.setpoint(5,10);
			p1.showpoint();
	
			return 0;
		}
