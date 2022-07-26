 ///operator overloading(overload + operator)
#include<iostream>
using namespace std;
class complex
{
    float real,imag;
public:
    set(float x,float y)
    {
        real=x;
        imag=y;
    }
    void show()
    {
        cout<<real<<"+j"<<imag<<endl;
    }
    complex operator+(complex);
};

complex complex:: operator+( complex c1)
{
    complex c;
    c.real=real+c1.real;
    c.imag=imag+c1.imag;
    return c;
}
int main()
{
    complex A,B,C;
    A.set(10.0,20.0);
    B.set(20.0,30.0);
    C=A+B;
    A.show();
    B.show();
    C.show();
}
