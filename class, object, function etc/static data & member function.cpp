///static data member & static member function
#include<iostream>
using namespace std;
class item
{
    static int Count;
    int num;
public:
    void getdata(int a)
    {
        num=a;
        Count++;
    }
    void getcount()
    {
        cout<<Count;
    }
};
int item::Count;///this line is must if static data is declared in class
int main()
{
    item a,b,c;
    a.getcount();
    b.getcount();
    c.getcount();
    a.getdata(100);
    a.getcount();
    b.getdata(200);
    b.getcount();
    c.getdata(300);
    c.getcount();
    cout<<"after reading data"<<endl;
    a.getcount();
    b.getcount();
    c.getcount();
}
