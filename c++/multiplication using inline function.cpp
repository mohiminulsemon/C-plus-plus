///multiplication values using inline function
#include<iostream>
using namespace std;

inline float mul(float x,float y)
    {
        return(x*y);
    }
inline float cube(float x)
    {
        return(x*x*x);
    }

int main()
{
    int a;
    cin>>a;
    cout<<"multiplication ="<<mul(a,a)<<endl;
    cout<<"cubic ="<<cube(a);
}
