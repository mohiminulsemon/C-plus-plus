///find the volume of a cube,cylinder,rectangle(function overloading concept)
#include<iostream>
using namespace std;
int volume(float a)
{
    return a*a*a;
}
int volume(float a,float b)
{
    return 3.14*a*a*b;
}
int volume(float a,float b ,float c)
{
    return a*b*c;
}
int main()
{
    float a,b,c;
    cin>>a>>b>>c;
    cout<<"cube="<<volume(a)<<endl;
    cout<<"cylinder="<<volume(a,c)<<endl;
    cout<<"rectangle="<<volume(a,b,c)<<endl;
}
