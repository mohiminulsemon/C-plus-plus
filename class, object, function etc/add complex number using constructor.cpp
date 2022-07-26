///add complex number using constructor
#include<iostream>
using namespace std;
class complex
{
    float x,y;
public:
    complex(){}///constructor with no argument
    complex(float a)///constructor with one argument
    ///constructor defined by class name
    {
        x=y=a;
    }
    complex(float a,float b)///constructor with two argument
    {
        x=a;
        y=b;
    }
    void show()
    {
        cout<<x<<"+j"<<y<<endl;;
    }
    friend complex sum(complex,complex);
};
 complex sum(complex c1,complex c2)
{
   complex c3;
   c3.x=c1.x+c2.x;
   c3.y=c1.y+c2.y;
   return c3;
}

int main()
{
    complex A(2.2,3.2),B(3.5),C;
    C=sum(A,B);
    A.show();
    B.show();
    C.show();

}



