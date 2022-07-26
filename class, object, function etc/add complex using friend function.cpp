///add complex using friend function
#include<iostream>
using namespace std;
class Complex
{
    float real;
    float imag;
public:
    void get_input(float x,float y)
    {
       real=x;
       imag=y;
    }
    void show_output()
    {
        cout<<real<<"+j"<<imag;
    }
    friend Complex sum(Complex,Complex);
};
 Complex sum(Complex c1,Complex c2)
{
   Complex c3;
   c3.real=c1.real+c2.real;
   c3.imag=c1.imag+c2.imag;
   return c3;
}

int main()
{
    Complex x,y,z;
    x.get_input(5,2);
    y.get_input(7,5);
    z=sum(x,y);
    z.show_output();
}


