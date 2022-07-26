///using operator overloading add,sub,mul,div
#include<iostream>
using namespace std;
class Float
{
    float f1;
public:
    void set(float f)
    {
        f1=f;
    }
    float operator + (Float ob);
    float operator - (Float ob);
    float operator * (Float ob);
    float operator / (Float ob);
};

float Float::operator + (Float ob)
{
    return f1+ob.f1;
}
float Float::operator - (Float ob)
{
    return f1-ob.f1;
}
float Float::operator * (Float ob)
{
    return f1*ob.f1;
}
float Float::operator / (Float ob)
{
    return f1/ob.f1;
}

int main()
{
    Float ob[2];
    ob[0].set(5.43);
    ob[1].set(3.33);

    cout<<"addition: "<<ob[0]+ob[1];

    cout<<"\n\nsubtraction: "<<ob[0]-ob[1];

    cout<<"\n\nmultiplication: "<<ob[0]*ob[1];

    cout<<"\n\ndivision: "<<ob[0]/ob[1]<<endl;

}
