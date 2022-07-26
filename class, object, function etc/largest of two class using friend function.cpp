///find the largest of two class using friend function
#include<iostream>
using namespace std;
class ABC;
class XYZ
{
    int x;
public:
    void set_value(int i){x=i;}
    friend void max(XYZ,ABC);
};

class ABC
{
    int a;
public:
    void set_value(int i){a=i;}
    friend void max(XYZ,ABC);
};

void max(XYZ m,ABC n)///act like a normal function as we used friend
{
    if(m.x>=n.a)
        cout<<m.x;
    else cout<<n.a;
}
int main()
{
   ABC abc;
   abc.set_value(10);
   XYZ xyz;
   xyz.set_value(20);
   max(xyz,abc);
}

