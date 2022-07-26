///difference of  inline function and preprocessor macro
#include<iostream>
using namespace std;
#define max(a,b) (a>b?a:b)
inline int maxim(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int x=max(1,2);
    int y=maxim(1,2);
    cout<<x<<endl<<y;
}
