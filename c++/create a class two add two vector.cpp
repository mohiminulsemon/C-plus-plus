///create a class two add two vector
#include<iostream>
using namespace std;
class vector
{
    int a,b,c;
public:
    void get_input()
    {
        cin>>a>>b>>c;
    }
    void show()
    {
        cout<<a<<"i+"<<b<<"j+"<<c<<"k"<<endl;
    }
    friend vector  sum(vector,vector);
    void multiply(int);
};
vector sum(vector v1,vector v2)
{
    vector v;
    v.a=v1.a+v2.a;
    v.b=v1.b+v2.b;
    v.c=v1.c+v2.c;
    return v;
}
void vector:: multiply(int x)
{
    a=a*x;
    b=b*x;
    c=c*x;
}
int main()
{
    vector p,q,r;
    p.get_input();
    q.get_input();
    r=sum(p,q);
    r.show();
    r.multiply(5);
    r.show();
}
