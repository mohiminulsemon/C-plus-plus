///swap function
#include<iostream>
using namespace std;
class B;
class A
{
    int x;
public:
    void set(int a)
    {
        x=a;
    }
    void show()
    {
        cout<<x<<endl;
    }
    friend void swap(A &,B &);
};

class B
{
    int y;
public:
    void set(int a)
    {
        y=a;
    }
    void show()
    {
        cout<<y<<endl;
    }
    friend void swap(A &,B &);
};

void swap(A &a,B &b)
{
    int temp;
    temp =a.x;
    a.x=b.y;
    b.y=temp;
}

int main()
{
    A c1;
    B c2;

    c1.set(100);
    c2.set(200);

    cout<<"value before exchange"<<endl;
    c1.show();
    c2.show();

    swap(c1,c2);

    cout<<"values after exchange"<<endl;
    c1.show();
    c2.show();

}
