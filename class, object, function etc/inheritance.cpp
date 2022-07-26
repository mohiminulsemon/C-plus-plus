///inheritance
#include<iostream>
using namespace std;
class Area
{
   public:
       double height;
       double width;
};

class rectangle:public Area
{
public:
    rectangle(double x,double y)
    {
        height=x;
        width=y;
    }
    double area()
    {
      return height*width;
    }
};

class isosceles:public Area
{
public:
     isosceles(double x,double y)
    {
        height=x;
        width=y;
    }
    double area()
    {
      return 0.5*height*width;
    }
};

class cylinder:public Area
{
public:
    cylinder(double x,double y)
    {
        height=x;
        width=y;
    }
    double area()
    {
      return 2*3.1416*width*(height+width);
    }
};

int main()
{
    rectangle A(40,50);
    isosceles B(40,50);
    cylinder C(40,50);
    cout<<A.area()<<"\n"<<B.area()<<"\n"<<C.area()<<endl;
}
